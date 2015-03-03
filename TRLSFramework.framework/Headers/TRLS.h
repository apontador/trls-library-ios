//
//  TRLS.h
//  TRLS
//
//  Created by Tiago Pitteri on 22/10/14.
//  Copyright (c) 2014 LBS Local. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "TRLSVisitsController.h"

@interface TRLS : NSObject

#pragma mark - Attributes

typedef void (^ TRLSCallback)(NSString *deviceId, NSError *error);

+ (BOOL)isSandboxEnabled;
+ (void)setSandboxEnabled:(BOOL)value;
+ (BOOL)isPositionsLogEnabled;
+ (void)setPositionsLogEnabled:(BOOL)value;
+ (BOOL)isDebugLogEnabled;
+ (void)setDebugLogEnabled:(BOOL)value;
+ (void)setUserId:(NSString *)value;
+ (NSString *)getUserId;
+ (NSString *)getClientId;
+ (void)setClientId:(NSString *)value;
+ (NSString *)getClientSecret;
+ (void)setClientSecret:(NSString *)value;

+ (void)startWithExternalId:(NSString *)externalId clientId:(NSString *)clientId clientSecret:(NSString *)clientSecret name:(NSString *)name phone:(NSString *)phone photo:(UIImage *)photo callback:(TRLSCallback)callback;
+ (void)setDeviceToken:(NSData *)token;
+ (BOOL)applicationDidReceiveRemoteNotification:(NSDictionary *)userInfo;

@end