#include <ansi.h>

inherit "/std/char/doomnpc";

void create()
{
        set_name("扫地僧", ({ "saodi seng","seng"}) );
        set("long",@LONG
        一个身穿青袍的枯瘦僧人拿着一把扫帚，正在弓身扫地。这僧人年纪
不少，稀稀疏疏的几根长须已然全白，行动迟缓，有气没力，不似身有武功的
模样。
LONG
         );

        set("title",HIW"少林前辈"NOR);
        set("max_gin", 50000);
        set("max_kee", 10000000);                    
        set("max_sen", 50000);
        set("max_force",50000); 
        set("max_mana",50000);
        set("mana",50000);
        set("max_atman",50000);
        set("atman",100000);
        set("force",100000);
        set("force_factor",500);     
        set("combat_exp",99999999);
        set("cor",1000);
        set("cps",1000);   
        set("spi",200);
        set("per",30);
        set("str",200);
        set("age",85);
        set("bln",1000);
        set("con",1000);
        set("int",1000);
        set("chat_chance",3);
        set("chat_msg", ({
                "扫地僧双掌合十，不住的念颂佛号“我佛慈悲，善哉善哉”。\n",
                "扫地僧不住的摇头叹息，“施主修炼上乘武功过甚，已然戾气深重，命不久亦了。”\n"
        }) );


        set_skill("yijinjing", 300);
        set_skill("dodge", 300);
        set_skill("parry", 300);
        set_skill("force",300);
        set_skill("strike",300);
        set_skill("buddhism",400);
        set_skill("sword",300);
        set_skill("dagou-bang",300);
        set_skill("necromancy",300);
        set_skill("perception",300);

        map_skill("force","yijinjing");
        map_skill("strike","yijinjing");
        map_skill("parry","yijinjing");
        map_skill("dodge","yijinjing");
        map_skill("sword","yijinjing");

        prepare_skill("strike","yijinjing");

        set_temp("apply/damage",1000);


        set("chat_chance_combat",10);
        set("chat_msg_combat", ({
                (: exert_function,"swat" :),
        }) );

        set("auto_heal",1);
        setup();
         set_temp("apply/armor_vs_force",2000);
         set_temp("apply/armor_vs_spells",200);
         set_temp("apply/armor",2000);

        add_money("tenthousand-cash",10);
        carry_object(__DIR__"obj/saozhou");
//        carry_object(__DIR__"obj/sengpao")->wield();
        carry_rnd_equip(7,7);   
}                          

void init()
{
        set("shen",this_player()->query("shen")/2);
        return;
}
                             
int killed_enemy(object ob)
{
        command("sigh");
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

        victims = query_temp("beat");
        if( !mapp(victims) || !sizeof(victims) ) return ::die();
        vic = keys(victims);
        i = sizeof(vic);
        while(i--)
        {
                if( userp(player=find_player(vic[i])) && present(player,environment()) )
                {
                        tell_object(player,"你受到了奖励！你的武林声望提高了！\n");
                        player->add("wlshw",10);
                }
        }                       
        ::die();

}
/*
void die()
{      
        unconcious();
        "/cmds/imm/full"->main(this_object(),"");
        revive();
        return;
}
*/



