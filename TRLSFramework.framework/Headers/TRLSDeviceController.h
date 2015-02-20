//
//  TRLSDeviceController.h
//  TRLSLibrary
//
//  Created by Tiago Pitteri on 12/12/14.
//  Copyright (c) 2014 LBS Local. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "TRLSDeviceContainer.h"

@interface TRLSDeviceController : NSObject

typedef void (^ TRLSDeviceControllerCallback)(BOOL success);

+ (TRLSDeviceContainer *)getCurrentDevice;
+ (void)saveCurrentDevice:(TRLSDeviceContainer *)deviceContainer;
+ (void)createOrUpdateDevice:(TRLSDeviceContainer *)deviceContainer method:(NSString *)method callback:(TRLSDeviceControllerCallback)callback;
//+ (void)createDevice:(TRLSDeviceContainer *)deviceContainer method:(NSString *)method callback:(TRLSDeviceControllerCallback)callback;
//+ (void)updateDeviceWithInstallationId:(NSString *)installationId json:(NSString *)json token:(NSString *)token callback:(TRLSDeviceControllerCallback)callback;

@end