#include <ansi.h>

inherit "/std/char/doomnpc";

void create()
{
        set_name("庞斑", ({ "pang ban","pang","ban"}) );
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

        set("title",YEL"魔师"NOR);
        set("max_gin", 4000);
        set("max_kee", 8000);                    
        set("max_sen", 4000);
        set("max_force",10000); 
        set("max_mana",8000);
        set("mana",8000);
        set("max_atman",4000);
        set("atman",8000);
        set("force",10000);
        set("force_factor",250);     
        set("combat_exp",49999999);
        set("cor",100);
        set("cps",100);   
        set("spi",100);
        set("per",30);
        set("str",100);
        set("age",35);
        set("bln",100);

        set_skill("taomo-dafa", 300);
        set_skill("dodge", 300);
        set_skill("parry", 300);
        set_skill("unarmed",300);
        set_skill("force",300);
        set_skill("magic",300);
        set_skill("spells",300);

        map_skill("force","taomo-dafa");
        map_skill("unarmed","taomo-dafa");
        map_skill("parry","taomo-dafa");
        map_skill("dodge","taomo-dafa");
        map_skill("magic","taomo-dafa");
        map_skill("spells","taomo-dafa");

        set_temp("apply/damage",250);

/*
        set("chat_chance",3);
        set("chat_msg_combat", ({
                "浪翻云凝视着窗外的明月，姿态悠闲之极。\n",
                "浪翻云举起盛满了清溪流泉的酒壶喝了一大口，笑道：痛快，痛快！\n"
        }) );
*/
        set("chat_chance_combat",10);
        set("chat_msg_combat", ({
                (: exert_function,"swat" :),
                (: command,"conjure shade-sense" :),
        }) );

        set("auto_heal",1);
        setup();

        add_money("tenthousand-cash",1);
        carry_rnd_equip(5,7);   
}                          

void init()
{
        set("shen",-1*this_player()->query("shen")/10);
        return;
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

void die()
{
        mapping victims;
        string *vic;
        int i;
        object player;
        object ob, obj;

        ob = this_object()->query_temp("last_damage_from");
        if( ob && !ob->query("pangban_winner") && userp(ob) )
        {       
                message_vision(HIW"\n\n庞斑化为一道清烟消失在云间，地上只留下四个字："HIR"“血债血偿”\n"NOR,ob);
                obj = new("/d/xanadu/npc/obj/crystal.c");
                obj->move(ob);
                obj->set("owner",ob);
                message_vision("\n$N死后，尸体中飞出一块魔族水晶萦绕在$n周围，好像找到了它新的主人。\n\n"NOR,this_object(),ob);
        }
        victims = query_temp("beat");
        if( !mapp(victims) || !sizeof(victims) ) return ::die();
        vic = keys(victims);
        i = sizeof(vic);
        while(i--)
        {
                if( userp(player=find_player(vic[i])) && present(player,environment()) )
                {
                        tell_object(player,"你受到了奖励！你的武林声望提高了！\n");
                        player->add("wlshw",2);
                }
        }
        ::die();

}


