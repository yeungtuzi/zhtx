// recover.c

#include <ansi.h>
#define SYNTAX "指令格式：recover <使用者姓名> because <原因>\n"
#define SAVE_EXTENSION ".o"
#define SAVE_BAK ".bak.o"

inherit F_CLEAN_UP;

//private int do_recover_players(int day);

int main(object me, string arg)
{
	string name, reason;
	string status;
	string src;
	string dst;
//	string *dirs;
	status = wizhood(me);
	if( me!=this_player(1)
	|| wiz_level(me) < wiz_level(status) )
		return notify_fail("你没有权力使用这个指令。\n");

	if( !arg ) return notify_fail(SYNTAX);

//	if( sscanf(arg, "%d", day) && day >= 0) return do_purge_players(day);

	if( sscanf(arg, "%s because %s", name, reason)!=2 )
		return notify_fail(SYNTAX);

	seteuid(getuid());
	if( file_size(DATA_DIR + "login/" + name[0..0] + "/" + name + SAVE_EXTENSION)<0 )
		return notify_fail("没有这位使用者。\n");

//	rm(DATA_DIR + "login/" + name[0..0] + "/" + name + SAVE_EXTENSION);
	src = (DATA_DIR + "login/" + name[0..0] + "/" + name + SAVE_BAK);
	dst = (DATA_DIR + "login/" + name[0..0] + "/" + name + SAVE_EXTENSION);
	src = resolve_path(me->query("cwd"), src);
	dst = resolve_path(me->query("cwd"), dst);
	cp(src,dst);
	src = (DATA_DIR + "user/" + name[0..0] + "/" + name + SAVE_BAK);
	dst = (DATA_DIR + "user/" + name[0..0] + "/" + name + SAVE_EXTENSION);
        src = resolve_path(me->query("cwd"), src);
        dst = resolve_path(me->query("cwd"), dst);
	cp(src,dst);	
//	(DATA_DIR + "user/" + name[0..0] + "/" + name + SAVE_EXTENSION)->cp_file(DATA_DIR + "user/" + name[0..0] + "/" + name + SAVE_BAK);
	write( "恢复了使用者 " + capitalize(name) + " 的数据。\n");
	log_file("static/RECOVER", sprintf("[%s] %s recovered %s because %s.\n",
		ctime(time())[0..15], geteuid(this_player(1)), name, reason));

	return 1;
}


int help(object me)
{
write(@HELP
指令格式：recover <使用者姓名> because <原因>

恢复玩家数据
HELP
	);
    return 1;
}
