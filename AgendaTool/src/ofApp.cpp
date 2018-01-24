#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ac = new AgendaController ();
    mb = new MenuBar(ac, ofRectangle(0,0,ofGetWindowWidth(), 100));
    ac->setViewport (ofRectangle(100,100,ofGetWindowWidth() - 200, ofGetWindowHeight() - 100));
    ac->addModel(new ToDoItemModel(ToDoItemModel::provideID(), "Model 1"));
    ac->addModel(new ToDoItemModel(ToDoItemModel::provideID(), "Model 2"));
    ac->addModel(new ToDoItemModel(ToDoItemModel::provideID(), "Model 3"));
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    ac->draw();
    mb->draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
//    ofLog() << "mPressed " << button << endl;
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
//    ofLog() << "mReleased " << button << endl;
    AgendaView::releasedMouseOn(-1);
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

void ofApp::mouseScrolled(int x, int y, float scrollX, float scrollY)
{
    ac->scrollView(ofVec2f(scrollX,scrollY));
    ofLog() << "scroll " << scrollY << endl;
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
