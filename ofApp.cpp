#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(25);
	ofSetWindowTitle("openFrameworks");

	ofBackground(39);
	ofSetColor(255);
	ofNoFill();
}

//--------------------------------------------------------------
void ofApp::update() {

	ofSeedRandom(39);
}

//--------------------------------------------------------------
void ofApp::draw() {

	this->cam.begin();
	ofRotateY(ofGetFrameNum());

	for (int k = 0; k < 2; k++) {

		auto noise_seed_location = glm::vec3(ofRandom(1000), ofRandom(1000), ofRandom(1000));
		auto noise_seed_rotate = glm::vec3(ofRandom(1000), ofRandom(1000), ofRandom(1000));
		for (int i = 0; i < 30; i++) {

			auto x = ofMap(ofNoise(noise_seed_location.x * 0.005, i * 0.05 + ofGetFrameNum() * 0.05), 0, 1, -300, 300);
			auto y = ofMap(ofNoise(noise_seed_location.y * 0.005, i * 0.05 + ofGetFrameNum() * 0.05), 0, 1, -300, 300);
			auto z = ofMap(ofNoise(noise_seed_location.z * 0.005, i * 0.05 + ofGetFrameNum() * 0.05), 0, 1, -300, 300);

			ofPushMatrix();
			ofTranslate(x, y, z);

			ofRotateZ(ofMap(ofNoise(noise_seed_rotate.z * 0.005, i * 0.05 + ofGetFrameNum() * 0.001), 0, 1, -360, 360));
			ofRotateY(ofMap(ofNoise(noise_seed_rotate.y * 0.005, i * 0.05 + ofGetFrameNum() * 0.001), 0, 1, -360, 360));
			ofRotateX(ofMap(ofNoise(noise_seed_rotate.x * 0.005, i * 0.05 + ofGetFrameNum() * 0.001), 0, 1, -360, 360));

			ofDrawBox(ofMap(i, 0, 30, 5, 30));

			ofPopMatrix();
		}
	}

	this->cam.end();
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}