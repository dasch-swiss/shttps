/*
 * Copyright © 2016 Lukas Rosenthaler, Andrea Bianco, Benjamin Geer,
 * Ivan Subotic, Tobias Schweizer, André Kilchenmann, and André Fatton.
 * This file is part of Sipi.
 * Sipi is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License as published
 * by the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * Sipi is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * Additional permission under GNU AGPL version 3 section 7:
 * If you modify this Program, or any covered work, by linking or combining
 * it with Kakadu (or a modified version of that library) or Adobe ICC Color
 * Profiles (or a modified version of that library) or both, containing parts
 * covered by the terms of the Kakadu Software Licence or Adobe Software Licence,
 * or both, the licensors of this Program grant you additional permission
 * to convey the resulting work.
 * See the GNU Affero General Public License for more details.
 * You should have received a copy of the GNU Affero General Public
 * License along with Sipi.  If not, see <http://www.gnu.org/licenses/>.
 *//*!
 * \brief Implements socket handling as iostreams.
 */
#ifndef __shttp_sockstream_h
#define __shttp_sockstream_h


#include <iostream>
#include <cstdio>
#include <cstring>
#include <unistd.h>
#include <streambuf>

#ifdef SHTTPS_ENABLE_SSL

#include "openssl/bio.h"
#include "openssl/ssl.h"
#include "openssl/err.h"

#endif

namespace shttps {
    /*!
     * \brief Implementation of a iostream interface for sockets.
     *
     * SockStream implements the handling for TCP/IP sockets as a iostream. It inherits from streambuf
     * and implements the virtual functions underflow, overflow and sync. There is an internal buffer
     * with a fixed size that can be given to the constructor.
     *
     * Example on how to use SockStream:
     *
     *     int sock;
     *     ...
     *     sock = accept(…);
     *     ...
     *     SockStream sockstream(sock);
     *     istream ins(&sockstream);
     *     ostream os(&sockstream);
     *     ...
     *     string tmpstr;
     *     ins >> tmpstr; // reads a word
     *     os << "That's it";
     */
    class SockStream : public std::streambuf {
    private:
        char *in_buf;      //!< input buffer
        int in_bufsize;    //!< size of input buffer
        int putback_size;  //!<! since streams allow to put back a character, this is the sizee of the putback buffer. Must be at least 1
        char *out_buf;     //!< output buffer
        int out_bufsize;   //!< Size of output buffer
        int sock;          //!< Socket handle
#ifdef SHTTPS_ENABLE_SSL
        SSL *cSSL;         //!< SSL socket handle
#endif

        /*!
         * This method is called when the read buffer (in_buf) has been empties.
         * It reads data from the socket and puts it in_buf. See \class std::streambuf for more
         * information.
         *
         * \returns The next character available or traits_type::eof()
         */
        virtual int_type underflow(void);

        /*!
         * Puts the gives character into the out_buf. If the outbuf is full,
         * flushed the buffer to the socket.
         *
         * \param[in] ch The next character/byte to be put into the output buffer (out_buf).
         *
         * \returns Returns the next character or traits_type::eof()
         */
        virtual int_type overflow(int_type ch);

        /*!
         * Flushes the output buffer to the socket.
         *
         * \returns 0 on success, -1 on failure.
         */
        virtual int sync(void);

    protected:
    public:
        inline SockStream() {
            in_buf = out_buf = nullptr;
            in_bufsize = out_bufsize = 0;
            sock = -1;
            putback_size = 0;
        }

        /*!
         * Constructor of the iostream for sockets which takes the socket id and the size of the buffers
         * as parameters. Please note the istreams allow to put back a characater/byte already read.
         * Therefore we also provide a putpack buffer which has to have a minimal size of 1 (but can be larger).
         *
         * \param[in] sock_p Socket ID of an open socket for input/output
         * \param[in] in_bufsize_p Size of the input buffer (Default: 8192)
         * \param[in] out_bufsize_p Size of the output buffer (Default: 8192)
         * \param[in] putback_size_p Size of putback buffer which determines how many bytes already read can be put back
         */
        SockStream(int sock_p, int in_bufsize_p = 8192, int out_bufsize = 8192, int putback_size_p = 32);

#ifdef SHTTPS_ENABLE_SSL

        /*!
         * Constructor of the iostream for sockets which takes the socket id and the size of the buffers
         * as parameters. Please note the istreams allow to put back a characater/byte already read.
         * Therefore we also provide a putpack buffer which has to have a minimal size of 1 (but can be larger).
         *
         * \param[in] cSSL_p SSL Socket ID of an open socket for input/output
         * \param[in] in_bufsize_p Size of the input buffer (Default: 8192)
         * \param[in] out_bufsize_p Size of the output buffer (Default: 8192)
         * \param[in] putback_size_p Size of putback buffer which determines how many bytes already read can be put back
         */
        SockStream(SSL *cSSL_p, int in_bufsize_p = 8192, int out_bufsize = 8192, int putback_size_p = 32);

#endif

        /*!
         * Destructor which frees all the resources, especially the input and output buffer
         */
        ~SockStream();
    };

}

#endif
