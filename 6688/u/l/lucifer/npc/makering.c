#include <ansi.h>

inherit "/ldg/std/doomnpc";

string ask_me();
int consider();

void create()
{
          set_name(GRN"小孩"NOR, ({ "kid","xiao hai",}) );
        set("long",
                GRN"黑色的狗毛，尖尖的耳朵，多么可爱的一只小狼狗\n"
                "这就是思佛的看家小狗！\n"NOR
         );

        set("age",32);
/*
       set("str",100);
       set("dex",100);
       set("int",100);
       set("bln",100);
       set("con",100);
         set("per",30);
        set("cor",100);

          set("max_gin",10000);
          set("max_kee",20000);
         set("max_sen",10000);
          set("max_force",20000);
           set("force",2000000);
        set("force_factor",250);     
         set("combat_exp",30000000);
        set("bellicosity",50000);

        set_skill("kuihua-shengong",220);
        set_skill("move",200);
        set_skill("xuehe-shengong", 220);
        set_skill("dodge", 220);
        set_skill("parry", 220); 
        set_skill("strike",220);
        set_skill("mo-zhang-jue",220);
        set_skill("force",220);


        map_skill("strike","mo-zhang-jue");
        map_skill("parry","mo-zhang-jue");
        map_skill("dodge","kuihua-shengong");
        map_skill("force","xuehe-shengong");
        prepare_skill("strike","mo-zhang-jue");

        set_temp("apply/attack",100);
        set_temp("apply/dodge",100);
        set_temp("apply/armor",300);
        set_temp("apply/armor_vs_force",200);
       set("chat_chance_combat", 100);
*/
        set("chat_msg_combat", ({
                (: consider :),
        }) );


        setup();
//         if(random(100)>90) carry_object("/u/l/lucifer/obj/ling1");
            carry_rnd_equip(6,6);   
}

void init()
{
        return 1;
}

int consider()
{
        if( !query("powerup")) 
        {
                command("exert powerup");
                set("powerup",1);
                return 0;
        }
        command("exert yiqi");
        return 1;
}
/*

void die()
{
        object ob, obj;

        ob = this_object()->query_temp("last_damage_from");
        if( ob && !ob->query("renkuang_winner") && userp(ob) )
        {       
                 message_vision(HIR"\n\n小狗临死之前吼道：思佛一定会给我报仇的！！！！\n"NOR,ob);
                obj = new("/d/moyu/swamp/npc/obj/ling.c");
                obj->move(ob);
                obj->set("owner",ob);
                message_vision("\n$N死后，$n不屑的扫了尸体一眼，突然发现一枚令牌，急忙捡了起来。\n"NOR,this_object(),ob);
        }

        ::die();
*/
