#pragma once
#include <OgreSceneManager.h>
#include <OgreSceneNode.h>
#include <OgreEntity.h>
#include <OgreMeshManager.h>
#include <OgreInput.h>
#include <SDL_keycode.h>

class Toy : public OgreBites::InputListener
{
public:
	Toy(Ogre::SceneNode* scene);
	~Toy();
	//virtual void frameRendered(const Ogre::FrameEvent &  evt);
	virtual bool keyPressed(const OgreBites::KeyboardEvent& evt);
	/*virtual bool keyReleased(const OgreBites::KeyboardEvent& evt);
	virtual bool mousePressed(const OgreBites::MouseButtonEvent& evt);
	virtual bool mouseRelease(const OgreBites::MouseButtonEvent& evt);
	virtual bool mouseMoved(const OgreBites::MouseMotionEvent& evt);
	virtual bool mouseWheelRolled(const OgreBites::MouseWheelEvent& evt);*/

protected:
	Ogre::SceneNode* mSceneNode;
	Ogre::SceneManager* mSM = nullptr;
	Ogre::SceneNode* mCabezaNodo = nullptr;
	Ogre::SceneNode* mNarizNodo = nullptr;
	Ogre::SceneNode* mCuerpoNodo = nullptr;
	Ogre::SceneNode* mOmbligoNodo = nullptr;
};

