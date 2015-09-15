//
//  LHSConnectionConfig.h
//  LivioHTTPServer
//
//  Created by Joel Fischer on 9/15/15.
//  Copyright © 2015 livio. All rights reserved.
//

#import <Foundation/Foundation.h>

@class LHSServer;

@interface LHSConnectionConfig : NSObject

- (id)initWithServer:(LHSServer *)server documentRoot:(NSString *)documentRoot;
- (id)initWithServer:(LHSServer *)server documentRoot:(NSString *)documentRoot queue:(dispatch_queue_t)q;

@property (weak, nonatomic, readonly) LHSServer *server;
@property (strong, nonatomic, readonly) NSString *documentRoot;
@property (assign, nonatomic, readonly) dispatch_queue_t queue;

@end
