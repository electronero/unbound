/*
 * iterator/iter_scrub.h - scrubbing, normalization, sanitization of DNS msgs.
 *
 * Copyright (c) 2007, NLnet Labs. All rights reserved.
 *
 * This software is open source.
 * 
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 
 * Redistributions of source code must retain the above copyright notice,
 * this list of conditions and the following disclaimer.
 * 
 * Redistributions in binary form must reproduce the above copyright notice,
 * this list of conditions and the following disclaimer in the documentation
 * and/or other materials provided with the distribution.
 * 
 * Neither the name of the NLNET LABS nor the names of its contributors may
 * be used to endorse or promote products derived from this software without
 * specific prior written permission.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED
 * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

/**
 * \file
 *
 * This file has routine(s) for cleaning up incoming DNS messages from 
 * possible useless or malicious junk in it.
 */

#ifndef ITERATOR_ITER_SCRUB_H
#define ITERATOR_ITER_SCRUB_H
struct msg_parse;
struct query_info;
struct region;

/**
 * Cleanup the passed dns message.
 * @param pkt: the packet itself, for resolving name compression pointers.
 *	the packet buffer is unaltered.
 * @param msg: the parsed packet, this structure is cleaned up.
 * @param qinfo: the query info that was sent to the server. Checked.
 * @param zonename: the name of the last delegation point.
 *	Used to determine out of bailiwick information.
 * @param region: where to allocate (new) parts of the message.
 * @return: false if the message is total waste. true if scrubbed with success.
 */
int scrub_message(ldns_buffer* pkt, struct msg_parse* msg, 
	struct query_info* qinfo, uint8_t* zonename, struct region* region);

#endif /* ITERATOR_ITER_SCRUB_H */
