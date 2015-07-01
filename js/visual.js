function drawPizza(){
	noStroke();
	fill(60, 150);
	ellipse((canvasWidth+2)/2,(canvasHeight+3)/2,752,752);
	fill(230,180,120);
	ellipse(canvasWidth/2,canvasHeight/2,750,750);
	fill(255,50,30);
	ellipse(canvasWidth/2,canvasHeight/2, 730,730);
	fill(255,255,0);
	ellipse(canvasWidth/2,canvasHeight/2, 715,715);
	
	for(var i = 0; i < slices; i ++){
	 	var theta = 2*PI/slices;
		stroke(70);
		strokeWeight(.3);
		line(canvasWidth/2, canvasHeight/2, canvasWidth/2 + 375* cos(theta*3/2 + i*theta - PI/2), canvasHeight/2 + 375 * sin(theta*3/2 + i*theta - PI/2));
		stroke(0);
		textSize(20);
		fill(0); 
		
	
		if (labelMode == 0){label = "";}
		if (labelMode == 2){label = i+1;}	
		if (labelMode == 1){label = i%2==0?(i/2)+1:'+';}
		if (labelMode == 3){label = label16ths[i];}

		
				
	
		text(label,(canvasWidth-13)/2 + (347)* cos((-PI/2)+i*(PI/(slices/2))), (canvasHeight+11)/2 + (347) * sin((-PI/2)+i*(PI/(slices/2))));
	}
}

function updatePepperonis(beat){
	var pepperoni = color(255,50,30);
	var pepper = color(0,102,0);
	var olive = color(10);
	var mushroom = color(214,184,153);
	var sausage = color(100,60,0);

	var colors = [sausage,pepperoni,pepper,mushroom,olive];

	for(var j = 0; j < 5; j++){
	//console.log("made it");
	for(var i = 0; i < slices; i ++){
	//console.log("made it2");
		if (i == beat){
			var rad = 35;
		}
		else var rad = 20;
		var theta = (-PI/2)+i*PI/(slices/2);		
		

		if(pizza[j][i] == 0){
			fill(255,225,0);
			noStroke();
		}
		else{
			
			fill(colors[j]);
			noStroke();
		}
		
			ellipse(canvasWidth/2 + (diams[j]/2) * cos(theta), canvasHeight/2 + (diams[j]/2) * sin(theta) ,rad + ((5-j)*4), rad + ((5-j)*4));			

			if(j == 4){
				fill(255,225,0);
				ellipse(canvasWidth/2 + (diams[j]/2) * cos(theta), canvasHeight/2 + (diams[j]/2) * sin(theta) ,rad -9, rad - 9);			

			}

	
	}
}

	
}