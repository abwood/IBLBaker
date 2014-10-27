//------------------------------------------------------------------------------------//
//                                                                                    //
//    ._____________.____   __________         __                                     //
//    |   \______   \    |  \______   \_____  |  | __ ___________                     //
//    |   ||    |  _/    |   |    |  _/\__  \ |  |/ // __ \_  __ \                    //
//    |   ||    |   \    |___|    |   \ / __ \|    <\  ___/|  | \/                    //
//    |___||______  /_______ \______  /(____  /__|_ \\___  >__|                       //
//                \/        \/      \/      \/     \/    \/                           //
//                                                                                    //
//    IBLBaker is provided under the MIT License(MIT)                                 //
//    IBLBaker uses portions of other open source software.                           //
//    Please review the LICENSE file for further details.                             //
//                                                                                    //
//    Copyright(c) 2014 Matt Davidson                                                 //
//                                                                                    //
//    Permission is hereby granted, free of charge, to any person obtaining a copy    //
//    of this software and associated documentation files(the "Software"), to deal    //
//    in the Software without restriction, including without limitation the rights    //
//    to use, copy, modify, merge, publish, distribute, sublicense, and / or sell     //
//    copies of the Software, and to permit persons to whom the Software is           //
//    furnished to do so, subject to the following conditions :                       //
//                                                                                    //
//    1. Redistributions of source code must retain the above copyright notice,       //
//    this list of conditions and the following disclaimer.                           //
//    2. Redistributions in binary form must reproduce the above copyright notice,    //
//    this list of conditions and the following disclaimer in the                     //
//    documentation and / or other materials provided with the distribution.          //
//    3. Neither the name of the copyright holder nor the names of its                //
//    contributors may be used to endorse or promote products derived                 //
//    from this software without specific prior written permission.                   //
//                                                                                    //
//    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR      //
//    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,        //
//    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL THE      //
//    AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER          //
//    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,   //
//    OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN       //
//    THE SOFTWARE.                                                                   //
//                                                                                    //
//------------------------------------------------------------------------------------//

#ifndef INCLUDED_BB_CAMERA_MANAGER
#define INCLUDED_BB_CAMERA_MANAGER

#include <IblPlatform.h>
#include <IblCamera.h>
#include <IblScene.h>

namespace Ibl
{
class DampenedInput;
class FocusedMovement;
class InputState;

class FocusedDampenedCamera
{
  public:
    FocusedDampenedCamera(Ibl::InputState* inputState);
    virtual ~FocusedDampenedCamera();

    //-----------------------------------------------------------
    // Initializes SensateCamera Managment
    // Checks that passed in pointers are valid before assigning.
    //-----------------------------------------------------------
    void                       create (Scene* scene);

    //-----------------------------------------------------------------------
    // Sets the current SensateCamera position rotation
    // the exact behaviour of this variable is defined by the movement policy
    //-----------------------------------------------------------------------
    void                       setRotation (Ibl::Vector3f& rotation);

    //-----------------------------------------------------------------------
    // Sets the current SensateCamera position translation
    // the exact behaviour of this variable is defined by the movement policy
    //-----------------------------------------------------------------------
    void                       setTranslation (Ibl::Vector3f& translation);
    bool                       update (float elapsedTime, 
                                       bool updateCameraInput = true, 
                                       bool forceUpdate = false);

    DampenedInput*             inputPolicy();
    FocusedMovement*           movementPolicy();

  private:
    Scene*                     _scene;

    //------------------
    // The input policy
    //------------------
    DampenedInput *            _inputPolicy;

    //----------------------------
    // The Camera Movement Policy
    //----------------------------
    FocusedMovement*           _movementPolicy;

    //---------------------
    // Translated Location
    //---------------------
    Ibl::Vector3f              _translation;
    
    //------------------------------------------
    // Rotation Angles for the movement policy
    //------------------------------------------
    Ibl::Vector3f              _rotation;
    Ibl::InputState*           _inputState;
};

}
#endif

