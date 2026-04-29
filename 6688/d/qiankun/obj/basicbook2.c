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
                        set_name(HIY"长生剑"NOR, ({"changsheng jian", "book"}));
                        set("skill", ([
                        "name": "sword",     
                        "sen_cost": 15+random(20),
                        "difficulty":   1,      
                        "max_skill":    200,  
                        "base_skill": 180,   
                        ]) );
                        break;
                case 1 :
                        set_name(HIW"太极十三式"NOR, ({"shisan shi","book"}));
                        set("skill", ([
                        "name": "force",     
                        "sen_cost": 15+random(20),
                        "max_skill":    200,  
                        "base_skill": 180,   
                        ]) );
                        break;
                case 2 :
                        set_name(HIG"碧玉刀"NOR, ({"biyu dao","book"}));
                        set("skill", ([
                        "name": "blade",     
                        "sen_cost": 15+random(20),
                        "max_skill":    200,  
                        "base_skill": 180,    
                        ]) );
                        break;
                case 3 :
                        set_name(HIR"踏雪无痕"NOR, ({"taxue wuhen","book"}));
                        set("skill", ([
                        "name": "dodge",     
                        "sen_cost": 15+random(20),
                        "max_skill":    200,  
                        "base_skill": 180,    
                        ]) );
                        break;
                case 4 :
                        set_name(HIM"掌法入门"NOR, ({"zhangfa rumen","book"}));
                        set("skill", ([
                        "name": "strike",     
                        "sen_cost": 15+random(20),
                        "difficulty":   1,      
                        "max_skill":    200,  
                        "base_skill": 180,  
                        ]) );
                        break;
                case 5 :
                        set_name(HIB"基本招架"NOR, ({"jiben zhaojia","book"}));
                        set("skill", ([
                        "name": "parry",     
                        "sen_cost": 15+random(20),
                        "difficulty":   1,      
                        "max_skill":    200,  
                        "base_skill": 180,   
                        ]) );
                        break;
                case 6 :
                        set_name(BLK"太祖长拳"NOR, ({"taizu changquan", "book"}));
                        set("skill", ([
                        "name": "unarmed",     
                        "sen_cost": 15+random(20),
                        "difficulty":   1,      
                        "max_skill":    200,  
                        "base_skill": 180,    
                        ]) );
                        break;
        }
        set_weight(10);
      //  set("unpawnable",1);
      //  set("no_paimai",1);
        set("no_drop",1);
        set("no_get",1);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "这是古龙先生留给我们的宝典，很珍贵的。
每本书对应一种基本武功，是江湖中武林高手进一步提高武功修为的好帮手。\n");
                set("unit", "本");
                set("value", 5000);
                set("material", "paper");
        }
        setup();
}

