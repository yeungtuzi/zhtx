#include <ansi.h>

inherit "/ldg/std/doomnpc";

string ask_me();
int consider();

void create()
{
        set_name(GRN"任狂"NOR, ({ "ren kuang","ren","kuang"}) );
        set("long",
                RED"瘦削的脸型，刀锋剑芒一般的眼光，满头的白发，破旧的衣衫，\n"
                "不知其年龄，但见此人微带文气，却令人感觉到一种前所未有的彪悍。\n"
                "这种感觉就像你跟一只疯狂的野兽，共处在一只关闭的笼子里。\n"
                "此人正是武林中名震天下，所向莫敌的“武林狐子”任狂！\n"NOR
         );

        set("title",GRN"武林狐子"NOR);
        set("age",32);
        set("int",100);
        set("cor",100);

        set("max_gin", 2000);
        set("max_kee", 4000);                    
        set("max_sen", 2000);
        set("max_force",4000); 
        set("force",10000);
        set("force_factor",250);     
        set("combat_exp",10000000);
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
        
        
        set("chat_chance_combat", 15);
        set("chat_msg_combat", ({
                (: consider :),
        }) );


        setup();
        carry_object("/d/moyu/obj/nineflower");
carry_rnd_equip(3,3);
carry_rnd_equip(3,3);
carry_rnd_equip(3,3);
carry_rnd_equip(3,3);
carry_rnd_equip(3,3);
carry_rnd_equip(3,3);
carry_rnd_equip(3,3);
carry_rnd_equip(3,3);
carry_rnd_equip(3,3);
carry_rnd_equip(3,3);
carry_rnd_equip(3,3);
carry_rnd_equip(3,3);
}

void init()
{
        return;
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

void die()
{
        object ob, obj;

        ob = this_object()->query_temp("last_damage_from");
        if( ob && !ob->query("renkuang_winner") && userp(ob) )
        {       
                message_vision(HIR"\n\n任狂临死之前吼道：这怎么可能！！！！\n"NOR,ob);
                obj = new("/d/moyu/swamp/npc/obj/ling.c");
                obj->move(ob);
                obj->set("owner",ob);
                message_vision("\n$N死后，$n不屑的扫了尸体一眼，突然发现一枚令牌，急忙捡了起来。\n"NOR,this_object(),ob);
        }

        ::die();
}
