//
//  LHSConnectionConfig.m
//  LivioHTTPServer
//
//  Created by Joel Fischer on 9/15/15.
//  Copyright © 2015 livio. All rights reserved.
//

#import "LHSConnectionConfig.h"

@implementation LHSConnectionConfig

- (id)initWithServer:(LHSServer *)aServer documentRoot:(NSString *)aDocumentRoot {
    if ((self = [super init])) {
        _server = aServer;
        _documentRoot = aDocumentRoot;
    }
    return self;
}

- (id)initWithServer:(LHSServer *)aServer documentRoot:(NSString *)aDocumentRoot queue:(dispatch_queue_t)queue {
    if ((self = [super init])) {
        _server = aServer;
        
        _documentRoot = [aDocumentRoot stringByStandardizingPath];
        if ([_documentRoot hasSuffix:@"/"]) {
            _documentRoot = [_documentRoot stringByAppendingString:@"/"];
        }
        
        if (queue) {
            _queue = queue;
        }
    }
    return self;
}

@end
