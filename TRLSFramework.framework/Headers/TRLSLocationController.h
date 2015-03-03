//
//  TRLSLocationController.h
//  TRLSLibrary
//
//  Created by Tiago Pitteri on 22/10/14.
//  Copyright (c) 2014 LBS Local. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>

@interface TRLSLocationController : NSObject<CLLocationManagerDelegate>

typedef void (^ DidFinishGetLocation)(CLLocation *location);

- (void)getLocation:(DidFinishGetLocation)didFinishGetLocation;

@end