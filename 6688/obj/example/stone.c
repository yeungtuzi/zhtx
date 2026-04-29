// stone.c
#include <ansi.h>
inherit ITEM;

mixed id = ({
                ({"twbxd","dan","bxd","twd","drug"}),
                ({"tbhhs","shan","tbh","hshan","fan"}),
                ({"yczzg","guan","zzg","ycguan","hat"}),
                ({"hbytz","zhu","hby","tianzh","pearl"}),
                });

string *name = ({
             CYN"天王补心丹"NOR,
             HIC"唐伯虎画扇"NOR,
             HIB"御赐珍珠冠"NOR,
             HIW"汉白玉天珠"NOR,
             });

void create()
{
        int i,j;
        i = random(sizeof(name));
        j = random(5);
        set_name(name[i], ({id[i][j]}) );
        set_weight(1);
        if( clonep() )
                set_default_object(__FILE__);
        else
        {
                set("unit", "个");
                set("long", "这就是传说中宝物，看起来不象吧！\n");
                set("value", 10000);
                set("unique",1);
                set("no_shown",1);
                set("no_drop",1);
                set("no_get",1);
                set("unpawnable", 1);
        }
        setup();

}

void init()
{
        add_action("do_give","give");
}

int do_give(string arg)
{
        string target,item;
        object who,me = this_player();

        if(!arg) return 0;

        if( sscanf(arg, "%s to %s", item, target)==2
        || sscanf(arg, "%s %s", target, item)==2 );
        else return 0;

        if(!id(item)) return 0;

        if(!objectp(who = present(target, environment(me))) || !living(who))
                return 0;

        if( !userp(who) && ( who->query("id") =="yin kaishan" || who->no_keep(this_object())))
        {
                set("no_drop",0);
                set("no_give",0);
        }

        return 0;
}


//防止大米帮挖宝扛尸体回去
varargs int move(mixed dest, int silently)
{
        if( objectp(dest) && dest->is_corpse() )
                dest->set_weight(20000000);
        return ::move(dest,silently);
}



