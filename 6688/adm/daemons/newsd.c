// newsd.c
// Created by dongsw@zhtx2 2002.8

#include <ansi.h>

inherit F_SAVE;
inherit F_DBASE;

#ifndef NEWS_CMD
#define NEWS_CMD          "/cmds/usr/news"
#endif

void create()
{
        seteuid(getuid());
        restore();
}

void read_news(object me)
{
        int num,l,n;
        mapping *notes;

        notes = NEWS_CMD->query("notes");

        if (! pointerp(notes) || ! sizeof(notes))
                return;

        num = sizeof(notes);
        l = me->query("LastReadNews");

          if ( !l) l=0;

        n = num - l;

        if (! n)
                tell_object(me, "\n本站所有新闻您都阅读过了，请您安心游戏吧。\n");
          else if (n == 1)
                tell_object(me, sprintf(WHT "最后第" HIW "%d"
                                        WHT "条新闻您尚未阅读。请等待" HIY "自动阅读" WHT "或\n使用 "
                                        HIY "news %d" WHT " 指令来阅读。\n" NOR,num,num));
        else
                tell_object(me, sprintf(WHT "\n您目前从第" HIY "%d"
                                        WHT " 条到第" HIY "%d" WHT " 条共"
                                        HIY "%s" WHT "条新闻还未曾阅读。\n请等待" HIY "自动阅读" WHT "或使用 "
                                        HIY "news" WHT " 指令阅读。\n" NOR,l+1,num,chinese_number(n)));

        //if (n>0)
        //me->start_call_out((: call_other, __FILE__, "auto_news", me :), 10 + random(10));
}

void auto_news(object me)
{
        int l,num,t;
        string cmd;
        num = sizeof(NEWS_CMD->query("notes"));
        l = me->query("LastReadNews");
        if (!l) l=0;
        if (l<num)
        {
        me->start_call_out((: call_other, __FILE__, "auto_news", me :), 20 + random(20));
        }
        else return;
        t = me->query("LastReadNews")+1;
        tell_object(me, HIG"\n晓风残月一边吃着批萨一边告诉您：\n"NOR);
        cmd = "news "+t;
        me->force_me(cmd);
}

