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

+ (void)startWithClientId:(NSString *)clientId clientSecret:(NSString *)clientSecret;
+ (void)startWithExternalId:(NSString *)externalId clientId:(NSString *)clientId clientSecret:(NSString *)clientSecret name:(NSString *)name phone:(NSString *)phone;
+ (void)setDeviceToken:(NSData *)token;
//+ (void)applicationDidReceiveLocalNotification:(UILocalNotification *)notification;
+ (BOOL)applicationDidReceiveRemoteNotification:(NSDictionary *)userInfo;

@end