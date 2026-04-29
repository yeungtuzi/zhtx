// dujiang.c 
// Update by dongsw@zhtx2

#include <ansi.h>

inherit F_DBASE;
inherit F_SSERVER;

int exert(object me, object target)
{
        string dest;
      object ob;

        mapping bank_bank = ([
                "/d/road/lzdukoun"    : "/d/road/lzdukoub",
                "/d/road/lzdukoub"    : "/d/road/lzdukoun",
                "/d/road/kfdukoun"    : "/d/road/kfdukoub",
                "/d/road/kfdukoub"    : "/d/road/kfdukoun",
                "/d/road/cqdukoun"    : "/d/road/cqdukoub",
                "/d/road/cqdukoub"    : "/d/road/cqdukoun",
                "/d/road/hkdukoun"    : "/d/road/hkdukoub",
                "/d/road/hkdukoub"    : "/d/road/hkdukoun",
                "/d/road/jldukoun"    : "/d/road/jldukoub",
                "/d/road/jldukoub"    : "/d/road/jldukoun",
                "/d/road/jndukoun"    : "/d/road/jndukoub",
                "/d/road/jndukoub"    : "/d/road/jndukoun",
                "/d/road/jsdukoud"    : "/d/road/jsdukoux",
                "/d/road/jsdukoux"    : "/d/road/jsdukoud",
        ]);

        if (objectp(ob = present("shui jing",this_player()) ) )
                return notify_fail("你不能在挖宝的时候飞来飞去的，不怕找到的宝物被神仙收走了？\n");  
        if( me->query("family/family_name") != "少林派"  )
        return notify_fail("你不是少林高僧不会使用「一苇渡江」绝技！\n");

        if( me->query_skill("shaolin-shenfa", 1) < 200 )
        return notify_fail("你的少林身法功力不够，无法施展「一苇渡江」绝技！\n");

        if( me->query_skill("hunyuan-yiqi", 1) < 200 )
        return notify_fail("你的混元一气功功力不够，无法施展「一苇渡江」绝技！\n");

        if( me->query_skill_mapped("dodge") != "shaolin-shenfa" )
        return notify_fail("你现在没有使用少林身法作为轻功的的特殊技能。\n");

        if( me->query("max_force") < 1500 || me->query("force") < 1000 )
        return notify_fail("你的内力不够，无法施展「一苇渡江」绝技！\n");

        if( undefinedp(dest = bank_bank[base_name(environment(me))]) )
        return notify_fail("此地不适合施展「一苇渡江」绝技！\n");

        message_vision(WHT"$N抽出一只芦苇抛向江心，然后飞身跳起。\n" +
        "接著$N用脚尖在芦苇上轻轻一点，借力用力好似神仙般飞过了大江。\n\n"NOR, me);

        me->add("force", - (100 + random(100)));
        me->move(dest);
        message_vision(HIG"\n$N飞身落地，吓的旁边的渔民们以为是神仙下凡！\n"NOR, me);

        return 1;
}

