#ifndef CURLTOOLS_H
#define CURLTOOLS_H

#include <boost/atomic.hpp>
#include <boost/filesystem/fstream.hpp>
#include <boost/optional.hpp>
#include <curl/curl.h>
#include <deque>
#include <set>

class cURLTools
{
public:
    static size_t CurlWrite_CallbackFunc_StdString(void* contents, size_t size, size_t nmemb,
                                                   std::deque<char>* s);
    static size_t CurlRead_CallbackFunc_StdString(void* dest, size_t size, size_t nmemb, void* userp);
    static int    CurlProgress_CallbackFunc(void*, double TotalToDownload, double NowDownloaded,
                                            double /*TotalToUpload*/, double /*NowUploaded*/);
    static void   CurlGlobalInit_ThreadSafe();
    static std::string GetFileFromHTTPS_withRetries(const boost::optional<uint64_t>& MaxRetries,
                                                    uint64_t           waitBetweenRetries_ms,
                                                    const std::string& URL, long ConnectionTimeout,
                                                    bool IncludeProgressBar);
    static std::string GetFileFromHTTPS(const std::string& URL, long ConnectionTimeout,
                                        bool IncludeProgressBar, bool VerifySSLHostAndPeer = true);
    static std::string PostJsonToHTTPS(const std::string& URL, long ConnectionTimeout,
                                       const std::string& data, bool chunked);
    static void        GetLargeFileFromHTTPS(const std::string& URL, long ConnectionTimeout,
                                             const boost::filesystem::path& targetPath,
                                             boost::atomic<float>&          progress,
                                             const std::set<CURLcode>& errorsToIgnore = std::set<CURLcode>());
    static int         CurlAtomicProgress_CallbackFunc(void* number, double TotalToDownload,
                                                       double NowDownloaded, double, double);
    static size_t      CurlWrite_CallbackFunc_File(void* contents, size_t size, size_t nmemb,
                                                   boost::filesystem::fstream* fs);
    static std::string GetUserAgent();
};

#endif // CURLTOOLS_H
