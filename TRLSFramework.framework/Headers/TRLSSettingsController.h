//
//  TRLSSettingsController.h
//  TRLSLibrary
//
//  Created by Tiago Pitteri on 22/10/14.
//  Copyright (c) 2014 LBS Local. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "TRLSSettingsContainer.h"

@interface TRLSSettingsController : NSObject

typedef void (^ TRLSSettingsCallback)();

+ (TRLSSettingsContainer *)getSettingsContainer;
+ (void)updateSettings:(TRLSSettingsCallback)callback;
+ (NSString *)getInstallationId;

@end