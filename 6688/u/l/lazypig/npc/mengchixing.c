#include <ansi.h>

inherit "/std/char/doomnpc";

void create()
{
        set_name("蒙赤行", ({ "meng chixing","meng"}) );
        set("long",@LONG
        他看上去只是三十许人，样貌近乎邪异的俊伟，尤使人印象深刻处，是其皮
肤晶莹通透，闪烁著炫目的光泽，一头乌黑亮光的长发，中分而下，垂在两边比一般
人宽阔得多的肩膀上。鼻梁高挺正直、双目神采飞扬，如若电闪，藏著近乎妖邪的魅
力，看一眼便包保毕生也忘不了，配合著有若渊停岳峙的身才气度，却使人油然心悸。
这活像魔王降世的男子，身上的紫红锈金华服一尘不染，外披一件长可及地的银色披
风，腰上束著宽三寸的围带，露出的一截缀满宝石，在阳光下异彩烁动，只是此带，
已价值连城。
LONG
         );

        set("title",YEL"天魔师"NOR);
        set("max_gin", 10000);
        set("max_kee", 20000);                    
        set("max_sen", 10000);
        set("max_force",20000); 
        set("max_mana",8000);
        set("mana",8000);
        set("max_atman",4000);
        set("atman",8000);
        set("force",10000);
        set("force_factor",500);     
        set("combat_exp",49999999);
        set("cor",100);
        set("cps",100);   
        set("spi",100);
        set("per",30);
        set("str",100);
        set("age",35);
        set("bln",100);

        set_skill("taomo-dafa", 400);
        set_skill("dodge", 400);
        set_skill("parry", 400);
        set_skill("unarmed",400);
        set_skill("force",400);
        set_skill("magic",400);
        set_skill("spells",400);

        map_skill("force","taomo-dafa");
        map_skill("unarmed","taomo-dafa");
        map_skill("parry","taomo-dafa");
        map_skill("dodge","taomo-dafa");
        map_skill("magic","taomo-dafa");
        map_skill("spells","taomo-dafa");

        set_temp("apply/damage",250);


        set("chat_chance_combat",10);
        set("chat_msg_combat", ({
                (: exert_function,"swat" :),
                (: command,"conjure shade-sense" :),
        }) );

        set("auto_heal",1);
        setup();

        add_money("tenthousand-cash",1);
        carry_rnd_equip(6,7);   
}                          

int init()
              {  object ob=this_player();
        set("shen",-1*this_player()->query("shen")/10);
     if ( ! wiz_level(ob) )
         ob->move("/d/snow/inn");
      return;
        return 1;
}
                             
int killed_enemy(object ob)
{
        command("heng");
}                 
                     
int chat()
{
        add("force",50);
        receive_curing("kee",50);
        receive_curing("sen",50);
        receive_curing("gin",50);
        ::chat();
}



