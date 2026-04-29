// search_file.c
// 写这个程序的目的是结合zh2的log系统一起清理垃圾文件
// 耗费资源，慎用！
// Written by dongsw

#include <ansi.h> 

// 此处可以设定根目录
#define BASE_PATH "/d/"
int if_c(int i, string *files, object me);
int if_in_roomlog(string file, object me);

int main(object me, string arg) 
{ 
        string *files, file;
        int i, t;
        
        files = get_dir(BASE_PATH + arg + "/");
        me->set("a",files);
        i = me->query("search_room_num");
        if( i == sizeof(files) )
        {
                write(BLINK HIC"目录检索完毕！\n"NOR);
                me->set("search_room_num",0);
                return 1;
        }
        
        if_c(i, files, me);
        i = me->query("search_room_num");
        if( i == sizeof(files) )
        {
                write(BLINK HIC"目录检索完毕！\n"NOR);
                me->set("search_room_num",0);
                return 1;
        }
        if (i<=sizeof(files))
        {
                file = BASE_PATH + arg + "/" + files[i];
                (if_in_roomlog(file, me)) ? (t = 1) : (t = 0);
                me->move(file);
                if( t == 0 )
                tell_object(me, BLINK + HIR + environment(me)->query("short") + NOR" 这个房间在ROOMLOG中不存在！\n");

                i++;
                me->set("search_room_num", i);
        }
        
        return 1;
} 

int if_c(int i, string *files, object me)
{
        int len;
        len = sizeof(files[i]);
        if ( files[i][(len-2)..(len-1)] != ".c" )
        {
                i++;
                me->set("search_room_num",i);
                if_c(i, files, me);
                return 1;
        }
}

int if_in_roomlog(string file, object me)
{
        int len;
        
        len = sizeof(file);
        file = file[0..(len-3)];

        if(strsrch(read_file("/quest/roomlog"), file) != -1)
        return 1;
        else return 0;
}
