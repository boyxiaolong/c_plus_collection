class BaseDispatcher
{
public:
    BaseDispatcher()          = default;
    virtual ~BaseDispatcher() = default;

    result_t Init(uint8_t idx)
    {
        //msgHandler.Init(idx);
        //to init pmsgHandlerVec
    };

    void Execute(MainControl &ctrl)
    {
    	for (int i = 0; i < pmsgHandlerVec.size(); ++i)
    	{
    		BaseHandler* phandler = pmsgHandlerVec[i];
    		bool res = phandler->handle_msg(txMsg, ctrl);
    		if (res)
    		{
    			break;
			}
		}
    };

protected:
    MsgInfo         txMsg;
    std::vector<BaseHandler*>      pmsgHandlerVec;
    static const char* sw = "Embedded Test Program";
};

class BaseHandler
{
	public:
		virtual bol handle_msg(const MsgInfo &msg, MainControl &ctrl) = 0;
}

class Handler1 : public BaseHandler
{
	public:
		virtual bool handle_msg(const MsgInfo &msg, MainControl &ctrl)
		{
			switch (msg.msgID)
        	{
            case REQ_PING:
                HandlePing(msg);
                break;
            case REQ_VERSION:
                HandleVersion(msg);
                break;
            default:
            	return false;
    		}
    		return true;
		}
}

class Handler2 : public BaseHandler
{
	public:
		virtual void handle_msg(const MsgInfo &msg, MainControl &ctrl)
		{
			switch (msg.msgID)
        	{
            case INFO_TEMP:
                HandleTemperature(msg, ctrl);
                break;
            default:
                HandleUnknown(msg);
    		}
		}
} 

class ChildOneDispatcher : public BaseDispatcher
{
    public:
        ChildOneDispatcher ()          = default;
        virtual ~ChildOneDispatcher () = default;

    void SpecificExecute(const MsgInfo &msg, MainControl &ctrl) override
    {
        switch (msg.msgID)
        {
            case INFO_TEMP:
                HandleTemperature(msg, ctrl);
                break;
            default:
                HandleUnknown(msg);
        }
    };

    protected:
        void HandleTemperature(const MsgInfo &msg, MainControl &ctrl)
        {
            float temperature = (float)ntohl(*(uint16_t*)msg.msgBuf) / 10;
            ctrl.GetRFMonitor().SetTemperature(temperature);
        };
};

Class MainController()
{
    public:
        Execute()
        {
            dispatcher.Execute(*this);
        }
    protected:
        ChildOneDispatcher   dispatcher;
}
