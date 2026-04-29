//modified by tlang for /cmds/std/look.c 

//this is for descripe a person's bellicosit for look.c
string *bel_msg_male1 = ({
        "脸上露出狡诈的神情，大概又想到了什么坏主意了。",
        "骄傲地昂着头，满脸不屑的神情。",        
});

string *bel_msg_male2 = ({
        "眉头紧锁，不知在想什么心事。",        
        "闷闷不乐。",
});

string *bel_msg_male3 = ({
        "脸上露出灿烂的笑容。", 
        "脸上露出愉快的微笑。",
});

string *bel_msg_female1 = ({
        "皱着小巧的鼻子，绷着个脸扮酷。",
        "头高高地抬起来，把天下所有的男人都不放在眼里似的。",   
});

string *bel_msg_female2 = ({
        "强颜欢笑，但掩饰不住心里的哀伤。",     
        "托着腮帮子作沉思状。",
});

string *bel_msg_female3 = ({
        "媚眼如丝。",
        "作小鸟依人状。",
        "作天真状。",           
});

string bel_status_msg(int bellicosity,string gender)
{
        if ( gender == "男性" ) {
                if ( bellicosity>=500 )        
                return ( bel_msg_male1[random(sizeof(bel_msg_male1))]); 
                else if ( bellicosity>=100 )
                return ( bel_msg_male2[random(sizeof(bel_msg_male2))]); 
                else if ( bellicosity<100 )
                return ( bel_msg_male3[random(sizeof(bel_msg_male3))]); 
        }                                                        
        if ( gender == "女性" ) {
                if ( bellicosity>=500 )
                return ( bel_msg_female1[random(sizeof(bel_msg_female1))]); 
                else if ( bellicosity>=100 )
                        return ( bel_msg_female2[random(sizeof(bel_msg_female2))]);
                else if ( bellicosity<100 )
                return ( bel_msg_female3[random(sizeof(bel_msg_female3))]);
        }
       else {
                if ( bellicosity>=500 )
                return ( bel_msg_male1[random(sizeof(bel_msg_female1))]); 
                else if ( bellicosity>=100 )
                        return ( bel_msg_male2[random(sizeof(bel_msg_female2))]);
                else if ( bellicosity<100 )
                return ( bel_msg_male3[random(sizeof(bel_msg_female3))]);
        }
}

//this is for descripe a person's per.
string *per_msg_male1 = ({
        "英俊潇洒,风度翩翩，气死潘安，羞死宋玉。" ,
        "相貌出众,面目俊朗，星目含情，剑眉露威。" ,
});

string *per_msg_male2 = ({
        "英俊潇洒,风度翩翩。",
        "相貌出众,面目俊朗。",
});
string *per_msg_male3 = ({
        "相貌平平，没什麽好看的。",
        "长得蔫蔫的，一副无精打采的模样。",
        "相貌凶恶，满脸横肉。",
});
string *per_msg_female1 = ({
        "容色秀丽，风姿绰约，有一段说不出的风流体态。",
        "长发如云，肌肤胜雪，不知倾倒了多少英雄豪杰。 ",
        "俏脸生春，妙目含情，轻轻一笑，不觉让人怦然心动。",
        "风情万种，楚楚动人，当真是我见犹怜。",
});
                
string *per_msg_female2 = ({
        "容色秀丽，风姿绰约，有一段说不出的风流体态。" ,
        "长发如云，肌肤胜雪，不知倾倒了多少英雄豪杰。 ",
        "俏脸生春，妙目含情，轻轻一笑，不觉让人怦然心动。",
        "风情万种，楚楚动人，当真是我见犹怜。 ",
});

string *per_msg_female3 = ({
        "虽算不上绝世佳人，也颇有几份姿色。 ",
        "长得还不错，颇有几份姿色。  ",
});
          
string per_status_msg(int per, string gender)
{          
        if ( gender == "男性" ) {
                if ( per>=25 )        
                return ( per_msg_male1[random(sizeof(per_msg_male1))]); 
                else if ( per>=20 )
                return ( per_msg_male2[random(sizeof(per_msg_male2))]); 
                else if ( per<20 )
                return ( per_msg_male3[random(sizeof(per_msg_male3))]); 
    }                                                        
        if ( gender == "女性" ) {
                if ( per>=25 )
                return ( per_msg_female1[random(sizeof(per_msg_female1))]); 
                else if ( per>=20 )
                        return ( per_msg_female2[random(sizeof(per_msg_female2))]);
                else if ( per<20 )
                return ( per_msg_female3[random(sizeof(per_msg_female3))]);

    }
	else {
                if ( per>=25 )        
                return ( per_msg_male1[random(sizeof(per_msg_male1))]); 
                else if ( per>=20 )
                return ( per_msg_male2[random(sizeof(per_msg_male2))]); 
                else if ( per<20 )
                return ( per_msg_male3[random(sizeof(per_msg_male3))]); 
    }                                   
}