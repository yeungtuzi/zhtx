//made by hacky
// Data: 1997.10.17

#include <ansi.h>
inherit NPC;

void create()
{
        set_name(HIC"观想兽"NOR, ({ "guanxiang shou", "shou", "beast" }) );
        set("race", "野兽");
        set("age", 10);
        set("long", "这是一只由修道人的杂念绮思所化的观想兽，会缠住人的魂魄。\n");
        set("str", 48);
        set("cor", 52);
        set("cps", 22);
        set("max_kee", 600);
        set("max_gin", 600);
        set("max_sen", 900);
        set("limbs", ({ "头部", "身体", "前脚", "後脚", "尾巴" }) );
        set("verbs", ({ "bite", "claw" }) );
        if( this_player() ) {
                set("combat_exp", this_player()->query_skill("taoism") * 2000);
                set("bellicosity",-(this_player()->query("shen")/random(this_player()->query("int"))));
        }
        set_temp("apply/attack", 60);
        set_temp("apply/armor", 40);
        setup();
}
