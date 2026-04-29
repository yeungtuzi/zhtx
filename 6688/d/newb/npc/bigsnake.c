///////////////////////////////////////////////////////
//------Newbie Area @ ZHTX2 -------------------------//
//------Made by flyaway -----------------------------//
//------------------------- Jun 2003 ----------------//
///////////////////////////////////////////////////////

#include <ansi.h>
inherit NPC;

void create()
{
        set_name(MAG"大蟒蛇"NOR, ({ "big snake","snake" }) );
        set("race", "野兽");
        set("age", 35);
        set("long", "一条长约六尺的大蟒蛇，在黑暗中眼睛发出可怕的绿光。\n");
        set("attitude", "peaceful");

        set("str", 26);
        set("cor", 30);

        set("limbs", ({ "头部", "身体" }) );
        set("verbs", ({ "bite", "claw" }) );

        set("combat_exp", 120000);
        set("bellicosity",1000);
//      set("shen_type", -1);

//      set("chat_chance", 6);
//      set("chat_msg", ({
//              (: this_object(), "random_move" :),
//      }) );

        set_temp("apply/attack", 30);
        set_temp("apply/damage", 10);
        set_temp("apply/armor", 2);

        setup();
}

void init()
{
        object ob;
        ::init();
        if (interactive(ob = this_player()) &&
                random(ob->query_kar() + ob->query_per()) < 30) {
                        remove_call_out("kill_ob");
                        call_out("kill_ob", 1, ob);
        }
}

