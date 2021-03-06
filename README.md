##Prerequisites
- iOS 8.0 or higher

##Frameworks
#####Add the frameworks below to your project:
- CoreLocation.framework
- Foundation.framework
- UIKit.framework
- QuartzCore.framework
- CoreGraphics.framework
- SystemConfiguration.framework
- libz.dylib
- CoreTelephony.framework

#####Property list file
Add the properties below to your project plist file:
- NSLocationAlwaysUsageDescription: Add any value, for example "Location Services"

#####Capabilities
Add the Background Modes below to your target:
- Remote notifications

##Cocoapods  
Add the TRLSFramework pod to your Podfile:
```objective-c
    pod 'TRLSFramework'
```

##Import the framework￼￼
1. Unarchive the zip file "TRLS.zip" and move the "TRLS" folder at the project root 
2. Select your project target, General tab and add the TRLS/Release/TRLSFramework.framework under Embedded Binaries
3. Select building settings tab and in the "Runpath Search Paths" and "Framework Search Paths" of your project target and test target add "$(PROJECT_DIR)/TRLS/$(CONFIGURATION)" for release and debug configurations

##Initialization
```objective-c
#import <TRLSFramework/TRLSFramework.h>

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {

    [TRLS startWithUserId:@"userId" clientId:@"clientId" clientSecret:@"clientSecret" name:@"deviceName" phone:@"devicePhoneNumber" photo:devicePhoto callback:^(NSString *deviceId, NSError *error) {
        
        if(error == nil) NSLog(@"Device created %@", deviceId);
        else NSLog(@"Error creating device %@", error.description);
        
      }];
    ];
    
}
```

#####Parameters:
- userId – Provide an ID for this device(can be null or empty) 
- clientId – Request a client id with TRLS dev team
- clientSecret – Request a client secret with TRLS dev team 
- deviceName – Can be null or empty
- devicePhoneNumber - Can be null or empty
- devicePhoto - Can be null of empty
- callback - Device creation callback

##Push notifications
The first step is to create an App ID and the associated SSL certificate on the Apple Developer website. This certificate will allow the Parse server to send push notifications to the application identified by the App ID. If you already created the App ID and the associated SSL certificate, send the p12 file to TRLS dev team(Section Configuring your App ID for Development Push Notifications): 

######Generating a Certificate Request
To begin, we'll need a certificate signing request file. This will be used to authenticate the creation of the SSL certificate.

1. Launch the Keychain Access application on your Mac.
2. Select the menu item Keychain Access > Certificate Assistant > Request a
Certificate From a Certificate Authority...
3. Enter your email address and name.
4. Select "Saved to disk" to download the .certSigningRequest file to your desktop.

######Creating an App ID
Every iOS application installed on your developer device needs an App ID. As a convention, these are represented by reversed addresses (ex. com.example.MyParsePushApp). For this
￼￼push app, you can use an App ID you've already created, but make sure it does not contain a wildcard character ("*"). The following instructions cover the creation of a new App ID.

1. Navigate to the Apple Developer Member Center(https://developer.apple.com/membercenter/index.action) website, and select Certificates, Identifiers & Profiles.
2. Select Identifiers from the iOS Apps section.
3. You will see a list of your iOS App IDs. Select the + button to register a new App Id.
4. Enter a name for your new App ID, then make sure to select the checkbox next to Push Notifications under App Services.
5. Choose an App ID Prefix. The default selection should be correct in most cases.
6. Under App ID Suffix, select Explicit App ID. Enter your iOS app's Bundle ID. This
string should match the Bundle Identifier in your iOS app's Info.plist.
7. Select "Continue" and make sure that all the values were entered correctly. Push Notifications should be enabled, and the Identifier field should match your app's Bundle Identifier (plus App ID Prefix). Select "Submit" to finalize the registration of your new App ID.

######Configuring your App ID for Development Push Notifications
Now that you've created an App ID (or chosen an existing Explicit App ID), it's time to configure the App ID for Push Notifications.

1. Select your newly created App ID from the list of iOS App IDs, then select "Settings".
2. Scroll down to the Push Notifications section. Here you will be able to create both a
Development SSL Certificate, as well as a Production SSL Certificate. Start by
selecting "Create Certificate" under "Development SSL Certificate".
3. The next screen will show instructions for creating a Certificate Signing Request
(CSR). This is the same .certSigningRequest file you created earlier. Select "Continue", then select "Choose File..." and locate the .certSigningRequest you created.
4. Select "Generate". Once the certificate is ready, select "Done" and download the generated SSL certificate from the "iOS App ID Settings" screen.
5. Double click on the downloaded SSL certificate to install it in your Keychain.
6. In Keychain Access, under "My Certificates", find the certificate you just added. It
should be called "Apple Development/Production IOS Push Services.
7. Right-click on it, select "Export Apple Development IOS Push Services:...", and save
it as a .p12 file. You will be prompted to enter a password which will be used to protect the exported certificate. Do not enter an export password when prompted! Note that you might have to enter your OS X password to allow Keychain Access to export the certificate from your keychain

######Creating the Provisioning Profile
A Provisioning Profile authenticates your device to run the app you are developing. Whether you have created a new App ID or modified an existing one, you will need to regenerate your provisioning profile and install it. If you have trouble using an existing profile, try removing the App ID and setting it back. For this tutorial, we'll create a new one.

1. Navigate to the Apple Developer Member Center(https://developer.apple.com/membercenter/index.action) website, and select Certificates, Identifiers & Profiles.
2. Select Provisioning Profiles from the iOS Apps section
3. Select the + button to create a new iOS Provisioning Profile.
4. Choose "iOS App Development" as your provisioning profile type then select
"Continue.
5. Choose the App ID you created from the drop down then select "Continue".
6. Make sure to select your iOS Development/Production certificate in the next screen,
then select "Continue".
7. You will be asked to select which devices will be included in the provisioning profile.
Select "Continue" after selecting the devices you will be testing with.
8. Choose a name for this provisioning profile, such as "My Push App Profile", then
select "Generate".
9. Download the generated provisioning profile from the next screen by selecting the
"Download" button.
10. Install the profile by double-clicking on the downloaded file.

######Registering the device
Now you must register the current device for push. If you already register your device for push notifications, go to step 3:

-  Create the method registerDeviceForPushNotifications in the app delegate: 
```objective-c
- (void)registerDeviceForPushNotifications{
  UIApplication *application = [UIApplication sharedApplication]; [application unregisterForRemoteNotifications];
  #if __IPHONE_OS_VERSION_MAX_ALLOWED >= 80000
    if ([application respondsToSelector:@selector(registerUserNotificationSettings:)]) {
      UIUserNotificationSettings *settings = [UIUserNotificationSettings settingsForTypes:UIUserNotificationTypeAlert | UIUserNotificationTypeBadge | UIUserNotificationTypeSound categories:nil];
      [application registerUserNotificationSettings:settings]; [application registerForRemoteNotifications];
    } else {
      [application registerForRemoteNotificationTypes: UIUserNotificationTypeSound | UIUserNotificationTypeAlert | UIUserNotificationTypeBadge];
    }
  #else
    [application registerForRemoteNotificationTypes: (UIRemoteNotificationTypeAlert | UIRemoteNotificationTypeBadge | UIRemoteNotificationTypeSound)];    
  #endif 
}
```
-  Call the method registerDeviceForPushNotifications before TRLS initialization in the app delegate’s application:didFinishLaunchingWithOptions: method:
```objective-c
- (BOOL)application:(UIApplication *)application
  didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    
    [self registerDeviceForPushNotifications];
    [TRLS startWithExternalId:@"externalId" clientId:@"clientId" name:@"deviceName" phone:@"devicePhoneNumber"];
    
}
```

Implement the callback method - application:didRegisterForRemoteNotificationsWithDeviceToken: in the app delegate. We need to inform TRLS about this new device:
```objective-c
- (void)application:(UIApplication *)app didRegisterForRemoteNotificationsWithDeviceToken:(NSData *)deviceToken {
  
    [TRLS setDeviceToken:deviceToken];
   
}
```
To handle a notification, implement the method below in the app delegate. If you already use your own push notification service, you need to verifiy if the notification is from a TRLS server:
```objective-c
- (void)application:(UIApplication *)application didReceiveRemoteNotification:(NSDictionary *)userInfo{
  
    if(![TRLS applicationDidReceiveRemoteNotification:userInfo]){
      //It's not a TRLS notification, you can process de push notification
    }else{
      //It's a TRLS notification, the library will process it automatically;
    }
  
}
```
##Customize the UI for Your App
Once you've set up your library integration, you can customize the UI to match the color scheme and branding of your app to ensure the best user experience for your users.

Import the class 
```objective-c
#import "TRLSMessageAppearance.h"
```
You can customize the following properties
```objective-c
    // Colors
    [TRLSMessageAppearance setTextColor:[UIColor blueColor]];
    [TRLSMessageAppearance setBackgroundColor:[UIColor grayColor]];
    [TRLSMessageAppearance setButtonBackgroundColor:[UIColor yellowColor]];
    [TRLSMessageAppearance setButtonTextColor:[UIColor greenColor]];
    [TRLSMessageAppearance setTitleColor:[UIColor blackColor]];
    
    //Fonts
    [TRLSMessageAppearance setTitleFont:[UIFont systemFontOfSize:9.0]];
    [TRLSMessageAppearance setButtonTextFont:[UIFont boldSystemFontOfSize:18.0]];
    [TRLSMessageAppearance setTextFont:[UIFont italicSystemFontOfSize:12.0]];
```


