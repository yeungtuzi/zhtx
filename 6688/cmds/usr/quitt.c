// quit.c

/*
 *  增加了自动清除首次连线时间小于一小时的玩家，
 *  这样可以节省内存，同时为自杀选人的玩家提供方便。
 */
//  by dongsw@zhtx2

#include <ansi.h>
#include <command.h>
#define __BAK_EXTENSION__  ".bak.o"

inherit F_DBASE;
inherit F_CLEAN_UP;

int file_purge(object me);
void create() 
{
        seteuid(getuid());
        set("name", "离线指令");
        set("id", "quit");
}

int main(object me, string arg)
{
        int i;
        object *inv, link_ob,ob;
        string *pk_id;
        
            if( me->query("mud_age")<600 && !wizardp(me))
        {
                  tell_object(me,HIR"您的首次连线时间尚未到达十分钟，还不能在本站永久储存档案。\n"
                               "如果您现在退出游戏，那么您的档案将被视作大米处理，不能永久保存。\n"
                               HIW"\n您确定要这么做吗？[Y/N]\n"NOR);
                input_to("dest_save", me, arg);
                return 1;
            }
                        
        if( !objectp(environment(me)) )
        {
                me->move("/d/snow/temple");
                me->set("startroom","/d/snow/temple");
                tell_object(me,"你的档案似乎出了点问题,下次进入的时候,会从这里连线开始.\n");
        }

        if( me->is_busy() ) {
                me->interrupt_me(me, "halt");
                write("Ok.\n");
                return 1;
        }
        if( raw_wiz_level(me) && me->query_temp("supervision") )
        {
                seteuid(getuid());
                me->enable_player();
                write("你恢复了普通用户身份。\n");
                me->delete_temp("supervision");
                return 1;
        }               
        if( !wiz_level(me) && me->query_condition("quit_delay") && !me->query_temp("netdead") )
        {
        if( me->query("combat_exp") > 50000 )
                return notify_fail("你尚有俗务未了,此刻还不能离开这个世界.\n");
        }
        if( !wizardp(me) && !me->query_temp("netdead") ) {
                inv = all_inventory(me);
                for(i=0; i<sizeof(inv); i++)
                          if( !inv[i]->query_autoload() )
                                DROP_CMD->do_drop(me, inv[i]);
        }

        link_ob = me->query_temp("link_ob");

        // We might be called on a link_dead player, so check this.
        if( link_ob ) {

                // Are we possessing in others body ?
                if( link_ob->is_character() ) {
                        write("你的魂魄回到" + link_ob->name(1) + "的身上。\n");
                        exec(link_ob, me);
                        link_ob->setup();
                        return 1;
                }

                link_ob->set("last_on", time());
                link_ob->set("last_from", query_ip_name(me));
                link_ob->save();
//              link_ob->save_back();
                destruct(link_ob);
        }

        write(HIG"欢迎您再次光临纵横天下II文字泥巴游戏！\n"NOR);
        message("system", me->name() + "离开游戏。\n", environment(me), me);

        CHANNEL_D->do_channel(this_object(), "sys",
                me->name() + "离开游戏了。");

        me->remove_all_enemy();
        pk_id=me->query_temp("pk_id");
        for(i=0;i<sizeof(pk_id);i++)
                if(ob=find_player(pk_id[i])) ob->remove_killer(me);
        me->dismiss_team();
        reset_eval_cost();
        me->save();
        reset_eval_cost();
//        me->save_back();
        destruct(me);

        return 1;
}
private void dest_save(string arg, object me)
{
        if( arg[0]=='y' || arg[0]=='Y' )
        {
                file_purge(me);
        }
        else 
        {
                tell_object(me,"\n请您继续游戏吧。\n");
        }
        
}

int file_purge(object me)
{
        object link_ob;
        string id;
        
        link_ob = me->query_temp("link_ob");
        if( !link_ob ) return 0;

        write(HIG"\n欢迎您再次光临纵横天下II！\n"NOR);

        seteuid(getuid());
        id = getuid(me);
        me->set_heart_beat(0);
        destruct(me);

        rm( link_ob->query_save_file() + __SAVE_EXTENSION__ );
        rm( link_ob->query_save_file() + __BAK_EXTENSION__ );
        rm( me->query_save_file() + __SAVE_EXTENSION__ );
        rm( me->query_save_file() + __BAK_EXTENSION__ );
        rm( "/data/mail/"+id[0..0]+"/"+id+".o" );
        
        return 0;
}
                
int help(object me)
{
        write(@HELP
指令格式 : quit

当你想暂时离开时, 可利用此一指令。
HELP
    );
    return 1;
}


