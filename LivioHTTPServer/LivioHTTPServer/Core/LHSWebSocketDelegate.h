//
//  LHSWebSocketDelegate.h
//  LivioHTTPServer
//
//  Created by Joel Fischer on 7/20/15.
//  Copyright © 2015 livio. All rights reserved.
//

#import <Foundation/Foundation.h>

@class LHSWebSocket;

NS_ASSUME_NONNULL_BEGIN

/**
 * There are two ways to create your own custom WebSocket:
 *
 * - Subclass it and override the methods you're interested in.
 * - Use traditional delegate paradigm along with your own custom class.
 *
 * They both exist to allow for maximum flexibility.
 * In most cases it will be easier to subclass WebSocket.
 * However some circumstances may lead one to prefer standard delegate callbacks instead.
 * One such example, you're already subclassing another class, so subclassing WebSocket isn't an option.
 **/
@protocol LHSWebSocketDelegate <NSObject>
@optional
- (void)webSocketDidOpen:(LHSWebSocket *)ws;
- (void)webSocket:(LHSWebSocket *)ws didReceiveMessage:(NSString *)msg;
- (void)webSocket:(LHSWebSocket *)ws didReceiveData:(NSData *)data;
- (void)webSocketDidClose:(LHSWebSocket *)ws;

@end

NS_ASSUME_NONNULL_END
