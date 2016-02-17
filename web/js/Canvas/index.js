import THREE from 'three';

import Umbrella from '../Umbrella';

const OrbitControls = require('three-orbit-controls')(THREE);

class Canvas {
    constructor() {

        // scene and camera
        this.scene    = new THREE.Scene();
        this.camera   = new THREE.PerspectiveCamera( 75, 480 / 320, 1, 10000 );
        this.camera.position.z = 100;
        this.camera.lookAt(new THREE.Vector3(0,0,0));

        this.controls = new OrbitControls(this.camera);

        // initialize renderer
        this.renderer = new THREE.WebGLRenderer();
        this.renderer.setSize( 480, 320 );

        // add to DOM
        document.getElementById('umbrella').appendChild( this.renderer.domElement );

        // begin loop
        this.loop();
    }
    loop() {
        requestAnimationFrame( () => this.loop() );
        this.renderer.render( this.scene, this.camera );
    }
    moveCameraUpDwn( amount ) {

        let _y = Math.cos(this.radians(amount)) * this.cameraZoom,
            _z = Math.sin(this.radians(amount)) * this.cameraZoom;

        this.camera.position.y = _y;
        this.camera.position.z = _z;
        this.camera.lookAt(new THREE.Vector3(0,0,0));
    }
    moveCameraLeftRight( amount ) {

        let _x = Math.cos(this.radians(amount)) * this.cameraZoom,
            _z = Math.sin(this.radians(amount)) * this.cameraZoom;

        this.camera.position.x = _x;
        this.camera.position.z = _z;
        this.camera.lookAt(new THREE.Vector3(0,0,0));
    }
    setCameraZoom( zoom ) {
        this.cameraZoom = zoom;
        this.moveCameraUpDwn(0);
        this.moveCameraLeftRight(0);
    }
    radians( degrees ) {
        return degrees * (Math.PI / 180);
    }
}

export default Canvas;
