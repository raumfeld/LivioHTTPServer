//
//  LHSServerDelegate.h
//  LivioHTTPServer
//
//  Created by Joel Fischer on 9/21/15.
//  Copyright © 2015 livio. All rights reserved.
//

#import <Foundation/Foundation.h>

@class LHSConnection;
@class LHSServer;
@class LHSWebSocket;


NS_ASSUME_NONNULL_BEGIN

@protocol LHSServerDelegate <NSObject>

@optional
- (void)serverDidStop:(LHSServer *)server;

- (void)server:(LHSServer *)server bonjourDidPublish:(NSNetService *)netService;
- (void)server:(LHSServer *)server bonjourPublishFailed:(NSNetService *)netService error:(NSDictionary *)errorDictionary;

- (void)server:(LHSServer *)server connectionDidStart:(LHSConnection *)connection;
- (void)server:(LHSServer *)server connectionDidClose:(LHSConnection *)connection;

- (void)server:(LHSServer *)server webSocketDidOpen:(LHSWebSocket *)socket;
- (void)server:(LHSServer *)server webSocketDidClose:(LHSWebSocket *)socket;

@end

NS_ASSUME_NONNULL_END
