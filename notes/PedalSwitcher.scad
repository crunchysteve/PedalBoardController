//  230 x 150 x 75

lid();
translate([0,0,4.2]) box();

module lid() difference(){
    linear_extrude(height=4) difference(){
        offset(5) offset(5) square([230,150],center=true);
        for(x=[-115,0,115]) for(y=[-75,75]){
            translate([x,y]) circle(2.5);
        }
    }
    translate([0,0,1.6]) linear_extrude(height=4) difference(){
        offset(5) offset(5) square([218,138],center=true);
        for(x=[-115,0,115]) for(y=[-74,75]){
            translate([x,y]) circle(7);
        }
    }
}

module box() difference(){
    linear_extrude(height=71,scale=[226/230,146/150]) difference(){
        offset(5) offset(5) square([230,150],center=true);
        for(x=[-115,0,115]) for(y=[-75,75]){
            translate([x,y]) circle(2.5);
        }
    }
    translate([0,0,-1.6]) 
            linear_extrude(height=71,scale=[226/230,146/150]) 
                    difference(){
        offset(5) offset(5) square([218,138],center=true);
        for(x=[-115,0,115]) for(y=[-74,75]){
            translate([x,y]) circle(7);
        }
    }
    for(x=[28:56:202]) translate([x-115,28-75,69]) cylinder(r=6,h=6);
    for(x=[28:56:202]) translate([x-115,48-76,69]) cylinder(r=3,h=6);
    for(x=[28:56:202]) translate([x-115,0,69]) cylinder(r=6,h=6);
    for(x=[28:56:202]) translate([x-115,19,69]) cylinder(r=3,h=6);
    for(x=[-56:56:56]) translate([x,47,69]) cylinder(r=6,h=6);
    for(x=[-95:25:-20]) for(z=[15,35])
            translate([x,70,z]) rotate([-90,0,0]) cylinder(r=5,h=15);
    for(x=[20:25:95]) for(z=[15,35])
            translate([x,70,z]) rotate([-90,0,0]) cylinder(r=5,h=15);
    for(x=[-82.5,82.5])
            translate([x,70,55]) rotate([-90,0,0]) cylinder(r=5,h=15);
    color("black"){
        translate([-119,-50,70.5]) 
                linear_extrude(height=20) text(text="B/P->",size=6);
        translate([-119,-3,70.5]) 
                linear_extrude(height=20) text(text="Sel->",size=6);
        translate([-85,45,70.5]) 
                linear_extrude(height=20) text(text="P- ->",size=5);
        translate([-9,30,70.5]) 
                linear_extrude(height=20) text(text="B/P A",size=5);
        translate([70,45,70.5]) 
                linear_extrude(height=20) text(text="<- P+",size=5);
        translate([79,-65,70.5]) 
                linear_extrude(height=20) text(text="A",size=6);
        translate([23,-65,70.5]) 
                linear_extrude(height=20) text(text="B",size=6);
        translate([-34,-65,70.5]) 
                linear_extrude(height=20) text(text="C",size=6);
        translate([-91,-65,70.5]) 
                linear_extrude(height=20) text(text="D",size=6);
    }
}
