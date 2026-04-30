
// jzz.c 「金钟罩」
// copy from xkx jinzhongzhao 

#include <ansi.h>

inherit F_DBASE;
inherit F_SSERVER;

int exert(object me, object target)
{
        // 2026-04-30: unused variable commented out
        // string msg;
        int i, extra;

        if( me->query("family/family_name") != "少林派")
                return notify_fail("你不是少林弟子不会使用「金钟罩」。\n");
                
        if( me->query_temp("pfm/shaolin_jzz") )
                return notify_fail("你正在运用「金钟罩」神功！\n");

        if( me->query_skill_mapped("force") != "hunyuan-yiqi")
                return notify_fail("你所用的内功与「金钟罩」神功相悖！\n");

        if( (int)me->query_skill("hunyuan-yiqi", 1) < 150 )
                return notify_fail("你的内功修为火候未到，还未领悟「金钟罩」神功！\n");

        if( (int)me->query_skill("jingang-quan", 1) < 150 )
                return notify_fail("你的金刚拳火候未到，还未练成「金钟罩」神功！\n");

        if( me->query("max_force") < 1000 )
                return notify_fail("你的内力不够，劲力不足以施展「金钟罩」神功！\n");
        
        if( me->query("force") < 1000 )
                return notify_fail("你的内力不够。\n");

        message_vision(
        HIY"$N双手合十，梵唱之声不绝于耳，面上宝相庄严，隐隐似有精光流转，"
        "\n身上袈裟无风自动，不带丝毫霸气，正是佛门不传之秘「金钟罩」神功！\n"NOR,me);
        me->add("force", -600);

        extra = me->query_skill("hunyuan-yiqi",1);
        me->set_temp("pfm/shaolin_jzz", 1);

        me->start_call_out( (: call_other, __FILE__, "remove_effect", me :), extra/2);

        return 1;
}

void remove_effect(object me)
{       
        if (me->query_temp("pfm/shaolin_jzz")) {
        me->delete_temp("pfm/shaolin_jzz");
        tell_object(me, YEL"\n因神功施展过久，恐对身体有害，你连忙卸去护体神功。\n"NOR);
}
}



