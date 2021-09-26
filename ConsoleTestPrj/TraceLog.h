//////////////////
//调试日志输出的宏定义, by zdleek
#define ZD_TRACE_LOG_ENABLE  //启用调试日志
//#undef ZD_TRACE_LOG_ENABLE   //禁用调试日志

#ifdef ZD_TRACE_LOG_ENABLE

#define ZD_TRACE_NORMAL(str,...) \
						{ \
							CString strInfo;\
							strInfo.Format(str, __VA_ARGS__);\
							CTraceService::TraceString(strInfo, TraceLevel_Normal);\
						}
						
#define ZD_TRACE_EXCEPT(str,...) \
						 { \
							CString strInfo;\
							strInfo.Format(str, __VA_ARGS__);\
							CTraceService::TraceString(strInfo, TraceLevel_Exception);\
						}

#else

#define ZD_TRACE_NORMAL(str,...)  {}
#define ZD_TRACE_EXCEPT(str,...)  {}

#endif
///end调试日志宏定义///////////////////