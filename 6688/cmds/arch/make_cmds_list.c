// cmds_list.c
// 用来生成本MUD所有命令列表
// Written by dongsw


// 此处可以设定根目录
#define BASE_PATH "/cmds/"

int main(object me) 
{ 
        string *cmds_dir, *cmds, arg, arg1;
        int i, k, len;
        
        cmds_dir = get_dir(BASE_PATH);
        arg1 = "";
        
        for(i=0;i<sizeof(cmds_dir);i++)
        {
                arg = BASE_PATH + cmds_dir[i] + "/";
                cmds = get_dir(arg);
                arg1 += arg + "\n\n";
                for(k=0;k<sizeof(cmds);k++)
                {
                        len = sizeof(cmds[k]);
                        arg1 += cmds[k][0..(len-3)] + " ";
                        if(k == sizeof(cmds) - 1)
                        arg1 += "\n\n";
                }
        }
        log_file("cmds_list", arg1, 0);
        return 1;
} 

