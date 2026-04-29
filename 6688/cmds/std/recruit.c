// recruit.c
// Update by dongsw 2003
// 增加派系系统，同派系之间可以相互拜师。

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
        object ob, old_rec;
        mapping family;
        int i;
        string myfam, obfam, mypart, obpart;

        if( !arg ) return notify_fail("指令格式：recruit [cancel]|<对象>\n");

        if( arg=="cancel" ) {
                old_rec = me->query_temp("pending/recruit");
                if( !objectp(old_rec) )
                        return notify_fail("你现在并没有收录任何人为弟子的意思。\n");
                write("你改变主意不想收" + old_rec->name() + "为弟子了。\n");
                tell_object(old_rec, me->name() + "改变主意不想收你为弟子了。\n");
                me->delete_temp("pending/recruit");
                return 1;
        }

        if( !(ob = present(arg, environment(me))) )
                return notify_fail("你想收谁作弟子？\n");

        if( ob==me ) return notify_fail("收自己为弟子？好主意....不过没有用。\n");

        if( userp(me) ) return notify_fail("玩家不能收徒。\n");

        if( ob->is_apprentice_of(me) ) {
                message_vision("$N拍拍$n的头，说道：「好徒儿！」\n", me, ob);
                return 1;
        }

        if( !me->query("family") )
                return notify_fail("你并不属於任何门派，你必须先加入一个门派，或自己创一个才能收徒。\n");

        if (ob->query("family"))
        {
                myfam = ob->query("family/family_name");
                mypart = PART_D->check_part_name(myfam);
        }

        if (me->query("family"))
        {
                obfam = me->query("family/family_name");
                obpart = PART_D->check_part_name(obfam);

        }        
        if( (object)ob->query_temp("pending/apprentice") == me )
        {

                if( !living(ob) ) {
                        message_vision(
                                "不过看样子$n显然没有办法行拜师之礼。\n\n",
                                me, ob);
                        return 1;
                }
                
                if( myfam && (myfam != obfam) ) 
                {
                        if( ob->query("wlshw") < 100 && ob->query("family/part_name") != "乾坤教")
                        {
                                tell_object(ob,"但是你的武林声望点数不足，不能够转换门派。\n");
                                return 1;
                        }
                        if (ob->query("family/part_name") != "乾坤教") ob->add("wlshw", -100);

                        if(obpart)
                                tell_object(ob,WHT"\n你决定在" + obpart + "中，由" +
                                        myfam + "转移到" + obfam + "学艺。\n\n"NOR);

                        message_vision("$N跪了下来向$n恭恭敬敬地磕了四个响头，叫道：「师父！」\n", ob, me);

                        if(obpart)
                                tell_object(ob, CYN"\n" + me->name() + CYN"：“" + 
                                        ob->name() + "，欢迎来到" + obpart + 
                                        "-" + myfam + "，本派系内部所有门派你都可以前去拜师学艺。”\n"NOR);

                }
                else
                {
                        message_vision(
                                "$n跪了下来向$N恭恭敬敬地磕了四个响头，叫道：「师父！」\n",
                                me, ob);

                        if(obpart)
                                tell_object(ob, CYN"\n" + me->name() + CYN"：“" + ob->name() + "，欢迎来到" + obpart + 
                                               "，本派系内部所有门派你都可以前去拜师学艺。”\n"NOR);
                                
                        //第一次拜师的新手给100点faith
                        if( !(ob->query("family")) && !ob->query("betrayer") )  
                                ob->set("faith",100);
                                
                }
                me->recruit_apprentice(ob);
                ob->delete_temp("pending/apprentice");

                if(obpart) ob->set("family/part_name", obpart);

                write("恭喜你新收了一名弟子！\n");
                family = ob->query("family");
                tell_object( ob, sprintf("\n恭喜您成为%s的第%s代弟子。\n", obfam,
                        chinese_number(family["generation"]) ));
                if(obpart)
                {
                        tell_object( ob, sprintf(HIG"\n您已经正式加入%s组织中的%s。\n"NOR, obpart, obfam));
                        PART_D->re_title(ob, obfam, obpart);
                }

                return 1;
        }
}

int help(object me)
{
        write(@HELP
指令格式 : recruit [cancel]|<对象>
 
这个指令能让你收某人为弟子, 如果对方也答应要拜你为师的话.
 
HELP
        );
        return 1;
}

