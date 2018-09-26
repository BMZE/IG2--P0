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
	mCuerpoNodo = mCabezaNodo->createChildSceneNode("nCuerpo");
	mCuerpoNodo->attachObject(cuerpo);
	mCuerpoNodo->setPosition(0,-250,0);
	mCuerpoNodo->setScale(1.5, 1.5, 1.5);
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
		float x = mCabezaNodo->getPosition().x;
		float y = mCabezaNodo->getPosition().y;
		float z = mCabezaNodo->getPosition().z;
		mCabezaNodo->setPosition(x, y, z+5);
	}
	
	return true;
}

Toy::~Toy()
{
}
