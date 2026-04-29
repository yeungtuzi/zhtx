// apprentice.c
// Update by dongsw 2003
// 增加派系系统，同派系之间可以相互拜师。

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
        object ob, old_app;
        mapping family, skills;
        int i;
        string myfam, obfam, mypart, obpart;

        if( !arg ) return notify_fail("指令格式：apprentice [cancel]|<对象>\n");

        if( arg=="cancel" ) {
                old_app = me->query_temp("pending/apprentice");
                if( !objectp(old_app) )
                        return notify_fail("你现在并没有拜任何人为师的意思。\n");
                write("你改变主意不想拜" + old_app->name() + "为师了。\n");
                tell_object(old_app, me->name() + "改变主意不想拜你为师了。\n");
                me->delete_temp("pending/apprentice");
                return 1;
        }

        if( !(ob = present(arg, environment(me)))
        ||      !ob->is_character() )
                return notify_fail("你想拜谁为师？\n");

        if( !living(ob) ) return notify_fail("你必须先把" + ob->name() + "弄醒。\n");

        if( ob==me ) return notify_fail("拜自己为师？好主意....不过没有用。\n");
         
        if( userp(ob) ) return notify_fail("玩家不能互相拜师,除非他开山立派.\n");

        if( me->is_apprentice_of(ob) ) {
                message_vision("$N恭恭敬敬地向$n磕头请安，叫道：「师父！」\n", me, ob);
                return 1;
        }

        if( !mapp( ob->query("family") ) )
                return notify_fail(ob->name() + "既不属於任何门派，也没有开山立派，不能拜师。\n");
         
        if (me->query("family"))
        {
                myfam = me->query("family/family_name");
                mypart = PART_D->check_part_name(myfam);
        }

        if (ob->query("family"))
        {
                obfam = ob->query("family/family_name");
                obpart = PART_D->check_part_name(obfam);

        }        

        if(!PART_D->if_same_part(myfam, obfam, me) && myfam && (myfam != obfam) )
        {
                tell_object(me,CYN + ob->query("name") + 
                        "说道：您已经是" + (mypart ? mypart : myfam) + 
                        "高手了，" + (obpart ? obpart : obfam) + "怎敢接纳！\n"NOR);
                        ob->fcommand("poor " + me->query("id"));
                        ob->fcommand("sigh");
                        return 1;
        }
        old_app = me->query_temp("pending/apprentice");
                
        if( ob==old_app )
                return notify_fail("你想拜" + ob->name() + "为师，但是对方还没有答应。\n");
        else if( objectp(old_app) ) 
        {
                write("你改变主意不想拜" + old_app->name() + "为师了。\n");
                tell_object(old_app, me->name() + "改变主意不想拜你为师了。\n");
        }
        me->set_temp("pending/apprentice", ob );

        if( userp(ob) )
                tell_object(ob, YEL "如果你愿意收" + me->name() + "为弟子，用 recruit 指令。\n" NOR);
        else
                ob->attempt_apprentice(me);
        
        return 1;
}

int help(object me)
{
        write(@HELP
指令格式 : apprentice [cancel]|<对象>
 
这个指令能让你拜某人为师，如果对方也答应要收你为徒的话，就会立即行
拜师之礼，否则要等到对方用 recruit 指令收你为弟子才能正式拜师。

请注意你已经有了师父，又背叛师门投入别人门下，所有技能会减半，并且
评价会降到零。

如果对你的师父使用这个指令，会变成向师父请安。
 
请参考相关指令 expell、recruit
HELP
        );
        return 1;
}

