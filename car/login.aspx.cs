using System;
using System.Configuration;
using System.Data;
using System.Linq;
using System.Web;
using System.Web.Security;
using System.Web.UI;
using System.Web.UI.HtmlControls;
using System.Web.UI.WebControls;
using System.Web.UI.WebControls.WebParts;
using System.Xml.Linq;

using System.Data.SqlClient;

public partial class _Default : System.Web.UI.Page 
{
    protected void Page_Load(object sender, EventArgs e)
    {
       // String sql = "select x,y from tab1";
      //  DataSet ds = RunQuery(sql);
       // DataTable dt = ds.Tables[0];
    }
    public System.Data.DataSet RunQuery(String QueryString)
    {
        SqlDataAdapter DBAdapter;
        DataSet ResultDataSet = new DataSet();
        String ConnectionString = "Data Source=.\\SQLEXPRESS;AttachDbFilename=E:\\car\\App_Data\\dbCar.mdf;Integrated Security=True;Connect Timeout=30;User Instance=True";
    
        SqlConnection DBConnection = new SqlConnection(ConnectionString);
       try
        {//建立DataSet
            DBAdapter = new SqlDataAdapter(QueryString, DBConnection);
            DBAdapter.Fill(ResultDataSet);
        }
        catch (Exception ex)
        {
            throw new Exception(ex.Message);
           // DBConnection.Close();
        }
        finally
        { 
            DBConnection.Close(); 
        }
        return ResultDataSet;
    }
    protected void Button1_Click(object sender, EventArgs e)
    {
        String user=TextBox1.Text;
        String pass=TextBox2.Text;
        
        String sql="select userName,passWord from tb_user where userName ='"+user+"'";
        DataSet ds=RunQuery(sql);
        DataTable dt = ds.Tables[0];
        if (ds != null)
        {
            Response.Redirect("main.aspx", true);
        }
        else {
            Session.Add("msg","该用户不存在，请重新输入");

        }
     
       
    }
}
