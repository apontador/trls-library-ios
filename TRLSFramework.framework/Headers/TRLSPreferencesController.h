//
//  TRLSPreferencesController.h
//  TRLSLibrary
//
//  Created by Tiago Pitteri on 22/10/14.
//  Copyright (c) 2014 LBS Local. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "TRLSSettingsContainer.h"

@interface TRLSPreferencesController : NSObject

+ (void)saveObjectWithKey:(NSString *)key andValue:(NSObject *)value;
+ (NSObject *)getObjectWithKey:(NSString *)key;
+ (NSString *)getInstallationId;

@end