#include <ansi.h>

inherit "/ldg/std/doomnpc";
inherit "/ldg/std/rnd_equipd";

string ask_me();
int consider();

void create()
{
        set_name(YEL"魑七"NOR, ({ "chi qi","chi","qi"}) );;
        set("long",
"他浑身上下一身尘土，就好像刚从地里爬出来的，但却身形魁伟，冷冷的目光让人不敢逼视。\n"
         );
         
        set("title",BLU"岩灵"NOR);
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
        set_skill("qishang-quan",220);
        set_skill("ill-quan",220);
        set_skill("xuanming-shenzhang",220);
        set_skill("move",200);
        set_skill("xuanyin-zhenqi", 220);
        set_skill("cuff",220);
        set_skill("hand",220);
        set_skill("dodge", 220);
        set_skill("parry", 220); 
        set_skill("strike",220);
        set_skill("nutrifux",220);
        set_skill("force",220);


        map_skill("hand","qishang-quan");
        map_skill("cuff","ill-quan");
        map_skill("parry","nutrifux");
        map_skill("dodge","kuihua-shengong");
        map_skill("force","xuanyin-zhenqi");
        prepare_skill("hand","qishang-quan");
        prepare_skill("cuff","ill-quan");
        
        set_temp("apply/attack",200);
        set_temp("apply/dodge",200);
        set_temp("apply/damage",200);
        set_temp("apply/armor",1000);
        set_temp("apply/armor_vs_force",1000);
        
        setup();

        if(random(10)>2) carry_rnd_equip(3,5);
        if( random(6) > 3) carry_object("/d/moyu/obj/nineflower");
        if( random(6) > 3) carry_object("/d/moyu/obj/nineflower");
        if( random(6) > 3) carry_object("/d/moyu/obj/nineflower");
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


