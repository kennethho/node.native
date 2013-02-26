#ifndef __LOOP_H__
#define __LOOP_H__

#include "base.h"
#include "error.h"

namespace native
{
    /*!
     *  Class that represents the loop instance.
     */
    class loop
    {
    public:
        /*!
         *  Default constructor
         *  @param use_default indicates whether to use default loop or create a new loop.
         */
        loop(bool use_default=false)
            : uv_loop_(use_default ? uv_default_loop() : uv_loop_new())
        { }

        /*!
         *  Destructor
         */
        ~loop()
        {
            if(uv_loop_)
            {
                uv_loop_delete(uv_loop_);
                uv_loop_ = nullptr;
            }
        }

        /*!
         *  Returns internal handle for libuv functions.
         */
        uv_loop_t* get() { return uv_loop_; }

        /*!
         *  Starts the loop. Always returns zero.
         *  Internally, this function just calls uv_run() function.
         */
        bool run() { return uv_run(uv_loop_)==0; }

        /*!
         *  Polls for new events once. Blocking if there is no event pending.
         *  Returns true if there is no event pending, or false if there are
         *  more events to be polled.
         *  Internally, this function just calls uv_run_once() function.
         */
        bool run_once() { return uv_run_once(uv_loop_)==0; }

        /*!
         *  ...
         *  Internally, this function just calls uv_update_time() function.
         */
        void update_time() { uv_update_time(uv_loop_); }

        /*!
         *  ...
         *  Internally, this function just calls uv_now() function.
         */
        int64_t now() { return uv_now(uv_loop_); }

        /*!
         *  Returns the last error occured in the loop.
         */
        error last_error() { return uv_last_error(uv_loop_); }

    private:
        loop(const loop&);
        void operator =(const loop&);

    private:
        uv_loop_t* uv_loop_;
    };

    /*!
     *  Starts the default loop. Always returns true.
     */
    inline bool run()
    {
        return uv_run(uv_default_loop()) == 0;
    }

    /*!
     *  Polls for new events once for the default loop. Blocking if there is no event pending.
     *  Returns true if there is no event pending, or false if there are
     *  more events to be polled.
     */
    inline bool run_once()
    {
        return uv_run_once(uv_default_loop()) == 0;
    }
}


#endif
