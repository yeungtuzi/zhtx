#include <ansi.h>

 inherit "/u/l/lucifer/npc/doomnpc";

void create()
{
        object sword;

        set_name("浪翻云", ({ "lang fanyun","lang","yun"}) );
        set("long",@LONG
        浪翻云身材高大，面貌粗犷，双眼细长而常常带上一种病态的黄色，使人不
欲久看。可是，浪翻云另带有一种神秘奇异的吸引力。
LONG
         );

        set("title",GRN"覆雨剑"NOR);
        set("max_gin", 4000);
        set("max_kee", 8000);                    
        set("max_sen", 4000);
        set("max_force",7000); 
        set("force",10000);
        set("force_factor",250);     
        set("combat_exp",69999999);
        set("cor",100);
        set("cps",100);
        set("bln",200);
        set("mana",6000);
        set("max_mana",8000);

        set_skill("fuyu-sword", 300);
        set_skill("dodge", 300);
        set_skill("mysterrier",300);
        set_skill("parry", 300);
        set_skill("sword",300);
        set_skill("force",300); //防止别人来弹指
        set_skill("mystforce",300);

        map_skill("sword","fuyu-sword");
        map_skill("parry","fuyu-sword");
        map_skill("dodge","mysterrier");
        map_skill("move","mysterrier");

        set_temp("apply/damage",250);

        set("chat_chance",3);
        set("chat_msg", ({
                "浪翻云凝视着窗外的明月，姿态悠闲之极。\n",
                "浪翻云举起盛满了清溪流泉的酒壶喝了一大口，笑道：痛快，痛快！\n"
        }) );

      set("chat_chance_combat",30);
        set("chat_msg_combat", ({
                (: perform_action,"move.hasten" :),
        }) );

        setup();

        carry_object(__DIR__"obj/fysword")->wield();
        add_money("tenthousand-cash",1);
        carry_rnd_equip(5,5);   
}                          

void init()
{
        set("shen",-1*this_player()->query("shen")/10);
        return 1;
}
                             
int killed_enemy(object ob)
{
        command("sigh");
}

void die()
{
        mapping victims;
        string *vic;
        int i;
        object player;
        object ob, obj;

        ob = this_object()->query_temp("last_damage_from");
        if( ob && !ob->query("lfy_winner") && userp(ob) )
        {       
                message_vision(YEL"\n\n浪翻云仰天长叹：“罢了，罢了，料我纵横半生，杀人无数。今天也要化为白骨埋入黄土，和寻常人有什么分别！”\n"NOR,ob);
                obj = new("/d/xanadu/npc/obj/key.c");
                obj->move(ob);
                obj->set("owner",ob);
                message_vision("\n$N死后，$n不屑的扫了尸体一眼，突然发现一把钥匙，急忙捡了起来。\n\n"NOR,this_object(),ob);
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


