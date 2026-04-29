#include <ansi.h>

inherit "/ldg/std/doomnpc";
inherit "/ldg/std/rnd_equipd";

string ask_me();
int consider();

void create()
{
        set_name(RED"魍五"NOR, ({ "wang wu","wang","wu"}) );;
        set("long",
                "他全身全身散发出炙热的光芒，但却黑漆漆的眼珠却好像地狱的深渊般看不到底。\n"
         );
         
        set("title",BLU"冥灵"NOR);
        set("age",32);
        set("str",50);
        set("cps",50);
        set("attitude", "aggressive");
        set("cor",50);

        set("max_gin", 20000);
        set("max_mana", 2000);
        set("mana", 4000);
        set("atman", 4000);
        set("max_atman", 2000);
        set("max_kee", 400000);                    
        set("max_sen", 20000);
        set("max_force",4000); 
        set("force",10000);
        set("force_factor",250);     
        set("combat_exp",40000000);
        set("bellicosity",5000);

        set_skill("kuihua-shengong",220);
        set_skill("move",200);
        set_skill("xuanyin-zhenqi", 220);
        set_skill("dodge", 220);
        set_skill("parry", 220); 
        set_skill("strike",220);
        set_skill("nutrifux",220);
        set_skill("force",220);


        map_skill("strike","nutrifux");
        map_skill("parry","nutrifux");
        map_skill("dodge","kuihua-shengong");
        map_skill("force","xuanyin-zhenqi");
        prepare_skill("strike","nutrifux");
        
        set_temp("apply/attack",120);
        set_temp("apply/dodge",120);
        set_temp("apply/damage",120);
        set_temp("apply/armor",1000);
        set_temp("apply/armor_vs_force",1000);
        
        setup();

        if(random(10)>2) carry_rnd_equip(2,4);
        if( random(5) > 2) carry_object("/d/moyu/obj/nineflower");
        if( random(5) > 2) carry_object("/d/moyu/obj/nineflower");
}
void init()
{
::init();
remove_call_out("greeting");
call_out("greeting", 1, this_player());
}

void greeting(object ob)
{
        object me, room1;
        if( !ob || !objectp(ob) ) return;
        me = this_object();
        room1 = environment(me);

        if (room1->query("no_fight"))
                room1->set("no_fight", 0);

        if (interactive(ob))
        {
                command("say 好久没吃这么新鲜的人肉了，这回可有口福了！！！\n");
                me->set_leader(ob);
                remove_call_out("kill_ob");
                call_out("kill_ob", 1, ob); 
        }       

}


