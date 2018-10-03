#include "Toy.h"
using namespace Ogre;


Toy::Toy(SceneNode* scene)
{
	mSceneNode = scene;
	mSM = mSceneNode->getCreator();

	//create Toy
	//create head
	Entity* cabeza = mSM->createEntity("sphere.mesh");
	mCabezaNodo = mSceneNode->createChildSceneNode("nCabeza");
	mCabezaNodo->attachObject(cabeza);
	mCabezaNodo->setScale(0.3, 0.3, 0.3);
	
	//create nose
	Entity* nariz = mSM->createEntity("sphere.mesh");
	mNarizNodo = mCabezaNodo->createChildSceneNode("nNariz");
	mNarizNodo->attachObject(nariz);
	mNarizNodo->setPosition(0, 0, 100);
	mNarizNodo->setScale(0.1, 0.1, 0.1);
	//create body
	Entity* cuerpo = mSM->createEntity("sphere.mesh");
	mCuerpoNodo = mSceneNode->createChildSceneNode("nCuerpo");
	mCuerpoNodo->attachObject(cuerpo);
	mCuerpoNodo->setPosition(0,-80,0);
	mCuerpoNodo->setScale(0.5, 0.5, 0.5);
	//create navel
	Entity* ombligo = mSM->createEntity("sphere.mesh");
	mOmbligoNodo = mCuerpoNodo->createChildSceneNode("nOmbligo");
	mOmbligoNodo->attachObject(ombligo);
	mOmbligoNodo->setPosition(0, 0, 100);
	mOmbligoNodo->setScale(0.1, 0.1, 0.1);

}

bool Toy::keyPressed(const OgreBites::KeyboardEvent& evt)
{
	if (evt.keysym.sym == SDLK_t)
	{
		mSceneNode->translate(0, 0, 5, Node::TS_LOCAL);
		mCabezaNodo->yaw(Ogre::Radian(1.0), Node::TS_LOCAL);
		mCuerpoNodo->pitch(Ogre::Radian(1.0), Node::TS_LOCAL);
	}
	else if (evt.keysym.sym == SDLK_y)
		moving = !moving;
	else if (evt.keysym.sym == SDLK_v)
	{
		mSceneNode->rotate(Ogre::Vector3(0, 1, 0), Ogre::Degree(45.0));
	}
	
	return true;
}

void Toy::frameRendered(const Ogre::FrameEvent &  evt) 
{
	if (moving) {
		mSceneNode->translate(0, 0, 30 * evt.timeSinceLastFrame, Node::TS_LOCAL);
		mCabezaNodo->yaw(Ogre::Radian(0.1), Node::TS_LOCAL);
		mCuerpoNodo->pitch(Ogre::Radian(0.1), Node::TS_LOCAL);
	}
}

Toy::~Toy()
{
}
