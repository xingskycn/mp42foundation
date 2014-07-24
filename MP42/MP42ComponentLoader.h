//
//  MP42ComponentLoader.h
//  MP42Foundation
//
//  Created by Damiano Galassi on 24/07/14.
//  Copyright (c) 2014 Damiano Galassi. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface MP42ComponentLoader : NSObject

+ (MP42ComponentLoader *)sharedLoader;

/**
 *  Load the built-in components
 *  located in Resources/Decoders .
 */
- (void)loadBundledComponents;

/**
 *  Load an old style audio component.
 */
- (OSStatus)loadComponent:(OSType)type
                   format:(OSType)format
             manufacturer:(OSType)manufactorer
                      url:(NSURL *)url
                    entry:(const char *)entry;

/**
 *  Load an audio component in the 10.7+ format.
 */
- (OSStatus)loadAudioComponent:(OSType)type
                        format:(OSType)format
                  manufacturer:(OSType)manufactorer
                           url:(NSURL *)url
                         entry:(const char *)entry;

@end
