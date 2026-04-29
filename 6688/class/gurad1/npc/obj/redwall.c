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
			set_name(YEL"长生剑"NOR, ({"changsheng jian", "book"}));
			set("skill", ([
                        "name": "sword",     
                        "sen_cost": 15+random(20),
                        "difficulty":   1,      
                        "max_skill":    300,     
    			]) );
			break;
		case 1 :
			set_name(BLK"离别钩"NOR, ({"libie gou", "book"}));
			set("skill", ([
                        "name": "unarmed",     
                        "sen_cost": 15+random(20),
                        "difficulty":   1,      
                        "max_skill":    300,     
    			]) );
			break;
		case 2 :
			set_name(HIC"碧玉刀"NOR, ({"biyu dao","book"}));
			set("skill", ([
                        "name": "blade",     
                        "sen_cost": 15+random(20),
                        "difficulty":   1,      
                        "max_skill":    300,     
    			]) );
			break;
		case 3 :
			set_name(RED"多情环"NOR, ({"duoqing huan","book"}));
			set("skill", ([
                        "name": "dodge",     
                        "sen_cost": 15+random(20),
                        "difficulty":   1,      
                        "max_skill":    300,     
    			]) );
			break;
		case 4 :
			set_name(MAG"愤怒的小马"NOR, ({"fennude xiaoma","book"}));
			set("skill", ([
                        "name": "strike",     
                        "sen_cost": 15+random(20),
                        "difficulty":   1,      
                        "max_skill":    300,     
    			]) );
			break;
		case 5 :
			set_name(HIW"孔雀令"NOR, ({"kongque ling","book"}));
			set("skill", ([
                        "name": "parry",     
                        "sen_cost": 15+random(20),
                        "difficulty":   1,      
                        "max_skill":    300,     
    			]) );
			break;
		case 6 :
			set_name(HIM"霸王枪"NOR, ({"bawang qiang","book"}));
			set("skill", ([
                        "name": "spear",     
                        "sen_cost": 15+random(20),
                        "difficulty":   1,      
                        "max_skill":    300,     
    			]) );
			break;
	}
	set_weight(10000000000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "这是古龙先生留下的秘籍，经验到一定阶段时可以参修(canxiu)，\n"
"整面墙上都是武功要旨，让人眼花燎乱。\n");
		set("unit", "面");
		set("value", 5000);
		set("material", "paper");
		set("no_study",1);
	}
	setup();
}

