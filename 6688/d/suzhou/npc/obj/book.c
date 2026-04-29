//book.c
//by tlang
//97.12

#include <ansi.h>
inherit ITEM;

void create()
{
	switch(random(6))
	{
		case 0:
			set_name(YEL"剑术基础"NOR, ({"basic sword", "book"}));
			set("skill", ([
                        "name": "sword",     
                        "sen_cost": 10+random(10),
                        "difficulty":   10, 
			"base_skill":   10,     
                        "max_skill":    50,     
    			]) );
			break;
		case 1 :
			set_name(BLK"太祖长拳"NOR, ({"royal unarmed", "book"}));
			set("skill", ([
                        "name": "unarmed",     
                        "sen_cost": 10+random(10),
                        "difficulty":   10,
			"base_skill":   10,      
                        "max_skill":    50,     
    			]) );
			break;
		case 2 :
			set_name(HIC"刀术指南"NOR, ({"basic blade","book"}));
			set("skill", ([
                        "name": "blade",     
                        "sen_cost": 10+random(10),
                        "difficulty":   10,
			"base_skill":   10,      
                        "max_skill":    50,     
    			]) );
			break;
		case 3 :
			set_name(RED"踏雪无痕"NOR, ({"basic dodge","book"}));
			set("skill", ([
                        "name": "dodge",     
                        "sen_cost": 10+random(10),
                        "difficulty":   10,
			"base_skill":   10,      
                        "max_skill":    50,     
    			]) );
			break;
		case 4 :
			set_name(MAG"掌法入门"NOR, ({"basic strike","book"}));
			set("skill", ([
                        "name": "strike",     
                        "sen_cost": 10+random(10),
                        "difficulty":   10,
			"base_skill":   10,      
                        "max_skill":    50,     
    			]) );
			break;
		case 5 :
			set_name(HIW"基本招架"NOR, ({"basic parry","book"}));
			set("skill", ([
                        "name": "parry",     
                        "sen_cost": 10+random(10),
                        "difficulty":   10,
			"base_skill":   10,      
                        "max_skill":    50,     
    			]) );
			break;
		case 6 :
			set_name(HIM"平气书"NOR, ({"buddism","book"}));
			set("skill", ([
                        "name": "buddism",     
                        "sen_cost": 10+random(10),
                        "difficulty":   10,
			"base_skill":   10,      
                        "max_skill":    50,     
    			]) );
			break;
	}
	set_weight(100);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "这是古龙先生留给我们的宝典，很珍贵的。
每本书对应一种基本武功，是镖局弟子拜师前学习功夫的好帮手。\n");
		set("unit", "本");
		set("value", 1000);
		set("material", "paper");
	}
	set("unpawnable",1);
	setup();
}

