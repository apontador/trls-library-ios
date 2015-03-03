//
//  TRLSMessageController.h
//  TRLSLibrary
//
//  Created by Tiago Pitteri on 22/10/14.
//  Copyright (c) 2014 LBS Local. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "TRLSMessageContainer.h"
#import <UIKit/UIKit.h>
#import <CoreLocation/CoreLocation.h>

@interface TRLSMessageController : NSObject

//typedef void (^ TRLSMessageCallback)(TRLSMessageContainer *message);
//
//+ (void)getMessageWithId:(NSString *)messageId showLoadingView:(BOOL)showLoadingView callback:(TRLSMessageCallback)callback;
//+ (void)getBeaconMessage:(CLBeacon *)beacon callback:(TRLSMessageCallback)callback;
//+ (void)showMessage:(TRLSMessageContainer *)messageContainer beacon:(CLBeacon *)beacon;
//+ (void)showMessageFromGeofence:(TRLSMessageContainer *)messageContainer fenceId:(NSString *)fenceId;

+ (void)showMessage:(NSString *)messageId fenceId:(NSString *)fenceId showLoadingView:(BOOL)showLoadingView showAlert:(BOOL)showAlert;
+ (void)showNotification:(TRLSMessageContainer *)messageContainer beacon:(CLBeacon *)beacon fenceId:(NSString *)fenceId showAlert:(BOOL)showAlert isGeofence:(BOOL)isGeofence isNoActionMessage:(BOOL)isNoActionMessage;
+ (void)showNotificationMessage:(TRLSMessageContainer *)messageContainer showAlert:(BOOL)showAlert isNoActionMessage:(BOOL)isNoActionMessage;

@end