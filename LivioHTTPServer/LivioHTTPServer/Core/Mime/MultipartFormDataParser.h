/**
 * This library is covered under the BSD 2-clause license below.
 * Software License Agreement (BSD License)
 *
 * ------------------------------------------------------------
 *
 * Copyright (c) 2011, Deusty, LLC
 * All rights reserved.
 *
 * Redistribution and use of this software in source and binary forms,
 * with or without modification, are permitted provided that the following conditions are met:
 *
 * * Redistributions of source code must retain the above
 *   copyright notice, this list of conditions and the
 *   following disclaimer.
 *
 * * Neither the name of Deusty nor the names of its
 *   contributors may be used to endorse or promote products
 *   derived from this software without specific prior
 *   written permission of Deusty, LLC.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * ------------------------------------------------------------
 *
 * This library was forked from it's original version, which can be found here: https://github.com/robbiehanson/CocoaHTTPServer
 * This library retains it's original license and is maintained by Livio.
 */

#import "MultipartMessageHeader.h"

/* 
Part one: http://tools.ietf.org/html/rfc2045 (Format of Internet Message Bodies)
Part two: http://tools.ietf.org/html/rfc2046 (Media Types)
Part three: http://tools.ietf.org/html/rfc2047 (Message Header Extensions for Non-ASCII Text)
Part four: http://tools.ietf.org/html/rfc4289 (Registration Procedures) 
Part five: http://tools.ietf.org/html/rfc2049 (Conformance Criteria and Examples) 
 
Internet message format:  http://tools.ietf.org/html/rfc2822

Multipart/form-data http://tools.ietf.org/html/rfc2388
*/

@class MultipartFormDataParser;

//-----------------------------------------------------------------
// protocol MultipartFormDataParser
//-----------------------------------------------------------------

@protocol MultipartFormDataParserDelegate <NSObject> 
@optional
- (void) processContent:(NSData*) data WithHeader:(MultipartMessageHeader*) header;
- (void) processEndOfPartWithHeader:(MultipartMessageHeader*) header;
- (void) processPreambleData:(NSData*) data;
- (void) processEpilogueData:(NSData*) data;
- (void) processStartOfPartWithHeader:(MultipartMessageHeader*) header;
@end

//-----------------------------------------------------------------
// interface MultipartFormDataParser
//-----------------------------------------------------------------

@interface MultipartFormDataParser : NSObject {
NSMutableData*						pendingData;
    NSData*							boundaryData;
    MultipartMessageHeader*			currentHeader;

	BOOL							waitingForCRLF;
	BOOL							reachedEpilogue;
	BOOL							processedPreamble;
	BOOL							checkForContentEnd;

#if __has_feature(objc_arc_weak)
	__weak id<MultipartFormDataParserDelegate>                  delegate;
#else
	__weak id<MultipartFormDataParserDelegate>     delegate;
#endif	
	int									currentEncoding;
	NSStringEncoding					formEncoding;
}

- (BOOL) appendData:(NSData*) data;

- (id) initWithBoundary:(NSString*) boundary formEncoding:(NSStringEncoding) formEncoding;

#if __has_feature(objc_arc_weak)
    @property(weak, readwrite) id delegate;
#else
    @property(unsafe_unretained, readwrite) id delegate;
#endif
@property(readwrite) NSStringEncoding	formEncoding;

@end
