//
//  TRLSMessageView.h
//  TRLSLibrary
//
//  Created by Tiago Pitteri on 22/10/14.
//  Copyright (c) 2014 LBS Local. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "TRLSMessageContainer.h"
#import <CoreLocation/CoreLocation.h>
#import "TRLSLocationController.h"

@interface TRLSMessageView : UIView

- (void)buildLayout:(TRLSMessageContainer *)messageContainer superview:(UIView *)superview;


@end