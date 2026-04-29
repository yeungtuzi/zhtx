// ling.c
//by masterall

#include <weapon.h>
#include <ansi.h> 
inherit DAGGER;
inherit F_AUTOLOAD;
int query_autoload()
{
        return query("weapon_prop");
}

void create()
{
        set_name(HIG"善赏"+HIW"罚恶"+HIY"令"NOR, ({ "shangshan fae ling","ling"}) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "柄");
                set("long", @long
    这就是多少武林人士梦寐以求的赏善罚恶令，它不但是一件无坚不摧的利器，更是一
种身份权力的象征，只有在武林中极具声望的人才配拥有这样神物。
long
);
                set("value", 0);
                set("material", "steel");
                set("rigidity", 200000);
                set("no_get", 1);
                set("no_put", 1);
                set("no_give", 1);
                set("no_paimai", 1);
                set("no_sell", 1);
                set("wield_msg", HIC"“铮”的一声$n"+HIC"已经在$N的手上，一种霸气，一份豪情尽在其中！！\n"NOR);
                set("unwield_msg", HIC"寒芒一闪，天地间恢复了平静。\n"NOR);
                set("weapon_prop/attack", 5+random(5)); 
                set("weapon_prop/dodge", 5+random(5)); 
                set("weapon_prop/parry", 5+random(5));
                set("weapon_prop/defense", random(5));
//                set("weapon_prop/speed", 20);
                set("weapon_prop/courage", 5+random(5)); 
                set("weapon_prop/composure", 5+random(5));
                set("weapon_prop/spirituality", 5+random(5)); 
        }
        init_dagger(50+random(50));      
        setup();
}

int wield()
{
       object me,ob;
       me = this_player();
       ob = this_object();

              if( !me->query("got_ling"))
                return notify_fail("你不是这件善赏罚恶令的主人，根本无法驾御它的力量。\n");

        return ::wield();
}


